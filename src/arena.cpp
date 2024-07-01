#include <cstring>
#include "arena.hpp"

namespace pe {

    template<class T>
    Arena<T>::Arena(const size_t size)
        : m_data(new T[size]), m_length(size), m_offset(0)
    {
    }

    template<class T>
    T* Arena<T>::push()
    {
        const auto size = sizeof(T);
        if (m_offset + size > m_length)
        {
            return nullptr;
        }
        m_offset += size;
        T* p = &m_data[m_offset];
        memset(p, 0, size);
        return p;
    }


}