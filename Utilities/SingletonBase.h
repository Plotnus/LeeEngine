#pragma once

// put this in the private section of singleton classes
#define DECLARE_SINGLETON(Class) friend class SingletonBase<Class>;

template<typename SingletonClass>
class SingletonBase
{
    static SingletonClass* m_Instance;

protected:
    SingletonBase() {}

public:
    static SingletonClass& Get()
    {
        if (m_Instance)
        {
            return *m_Instance;
        }
        else
        {
            m_Instance = new SingletonClass();
            return *m_Instance;
        }
    }
};

template<typename SingletonClass> SingletonBase::m_Instance = nullptr;
