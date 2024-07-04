#include <cstring>
#include "arena.hpp"

#include <iostream>

namespace pe {

    Arena::Arena(const size_t size)
        :  m_length(size), m_offset(0)
    {
        m_data = new char[size];
    }

    void* Arena::push(const size_t size)
    {
        if (m_offset + size > m_length)
        {
            std::cerr << "\nERROR: arena is full\n";
            return nullptr;
        }
        m_offset += size;
        void* p = &m_data[m_offset];
        memset(p, 0, size);
        return p;
    }


}
