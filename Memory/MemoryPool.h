#pragma once

#include "../PlatformAbstraction/IntegerDefines.h"

using namespace NPlatformTypes;

// TODO VERY IMPORTANT. this shit needs locking.

// BS must be divisible by 16
template <size_t BS>
struct PoolBlock
{
    char m_Memory[BS];
    u32 m_DebugBoundary;
    PoolBlock<BS>* m_pNext;

private:
    // if 32-bit, need 8 byte padding. if 64-bit, need only 4 bytes
    PTR_SIZE m_UnusedPadding;

public:
    PoolBlock()
    {
        m_pNext = nullptr;
        static_assert(BS % 16 == 0, "PoolBlock's size MUST BE divisible by 16");
    }

    void* operator new(size_t size)
    {
        // assert. poolblocks are designed to be allocated as an array. Not individually
        assert(false);
        return nullptr;
    }

    void operator delete(void* ptr)
    {
        // also assert
        assert(false);
    }

    void* operator new[](size_t size)
    {
#ifdef _MSC_VER
        return _aligned_malloc(size, 16);
#elif defined __unix__
        void* nptr = nullptr;
        posix_memalign(&nptr, 16, size);
        return nptr;
#endif
    }

    void operator delete[](void* ptr)
    {
#ifdef _MSC_VER
        _aligned_free(ptr);
#elif defined __unix__
        free(ptr); // can just use regular free with posix_memalign
#endif
    }
};

// block size and num blocks
template<size_t BS, u32 NB>
class MemoryPool
{
    // in itp 485, this was a singleton. However, in PE, it's not. I think it's best if it's not and we have
    // a singleton memory MANAGER instead? idk lol
public:
    void Init();
    void Shutdown();

    void* Alloc(size_t size);
    void  Free(void* ptr); // don't call this on random pointers. be smart :)
    u32   GetNumBlocksFree() const { return m_NumBlocksFree; }

protected:
    MemoryPool()
      : m_pPool(nullptr)
      , m_pFreeList(nullptr)
    {}

    PoolBlock<BS>* m_pPool; // first element of the array of poolblocks
    PoolBlock<BS>* m_pFreeList; // pointer represents the freelist. initially pointing to first element

    u32 m_NumBlocksFree;
};

template<size_t BS, u32 NB>
void MemoryPool<BS, NB>::Init()
{
    m_pPool = new PoolBlock<BS>[NB];
    m_pFreeList = m_pPool;

    for (i32 I = 0; I < NB; I++)
    {
        m_pPool[I].m_pNext = &(m_pPool[I + 1]);

#ifdef _DEBUG
        // initialize memory to something bogus (TODO)

        // and write a boundary value
        m_pPool[I].m_DebugBoundary = 0xcafebabe;
#endif
    }

    m_NumBlocksFree = NB;
}

template<size_t BS, u32 NB>
void MemoryPool<BS, NB>::Shutdown()
{
    delete[] m_pPool;

    m_pPool = nullptr;
    m_pFreeList = nullptr;
    m_NumBlocksFree = 0;
}

template<size_t BS, u32 NB>
void MemoryPool<BS, NB>::Alloc(size_t size)
{
    // (TODO) assert if
    // 1. size requested > block size
    // 2. no more free blocks

    PoolBlock<BS>* TopFree = m_pFreeList; // get a free block
    m_pFreeList = m_pFreeList->m_pNext;

    m_NumBlocksFree -= 1;

    return TopFree;
}

template<size_t BS, u32 NB>
void MemoryPool<BS, NB>::Free(void* ptr)
{
#ifdef _DEBUG
    char* minPtr = (char*) this;
    char* maxPtr = minPtr + NB * BS;

    // assert that ptr is between minPtr and maxPtr
    // should work...
#endif

    //we know that the address of the memory == address of the pool block
    // because memory is the first elem of poolblock
    PoolBlock<BS>* RealPtr = reinterpret_cast<PoolBlock<BS>*>(ptr);

#ifdef _DEBUG
    // sanity checks
    // assert that boundary == cafebabe
    // reset memory to whatever we set when we initialized
#endif

    RealPtr->m_pNext = m_pFreeList;
    m_pFreeList = RealPtr;

    m_NumBlocksFree += 1;
}
