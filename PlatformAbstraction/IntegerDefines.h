#pragma once

namespace NPlatformTypes
{
    typedef signed int      i32; // whaaaaaaat i totally didn't know you can do this. ints are 32 bits on 64 bit too! (generally)
    typedef unsigned int    u32;
}

#ifdef _MSC_VER // i'm guessing windows compiler defines this
namespace NWindowsSpecificTypes
{
#ifdef _WIN64
    #define PTR_SIZE 8
#elif defined _WIN32
    #define PTR_SIZE 4
#endif
}
#endif
