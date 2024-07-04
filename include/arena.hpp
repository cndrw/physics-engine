#ifndef ARENA_HPP
#define ARENA_HPP

namespace pe {

    class Arena final
    {
    public:
        explicit Arena(size_t size);
        void* push(size_t size);
        ~Arena() { delete[] m_data; }

    private:
        char* m_data;
        size_t m_length;
        size_t m_offset;
    };

}

#endif //ARENA_HPP
