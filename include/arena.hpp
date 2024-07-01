#ifndef ARENA_HPP
#define ARENA_HPP

namespace pe {

    template<class T>
    class Arena final
    {
    public:
        explicit Arena(size_t size);
        T* push();
        ~Arena() { delete[] m_data; }

    private:

    private:
        T* m_data;
        size_t m_length;
        size_t m_offset;
    };

}

#endif //ARENA_HPP
