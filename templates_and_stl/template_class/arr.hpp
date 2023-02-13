#include <cstdint>


template <typename T, std::size_t SZ>
struct array {
    // array of elements
    T elem[SZ];

    // returns size of the array, the template param SZ
    std::size_t size() const {
        return SZ;
    }

    T& operator[] (std::size_t _index) {
        return elem[_index];
    }

    const T& operator[](std::size_t _index) const {
        return elem[_index];
    }

    typedef T *iterator;

    iterator begin() {
        return &elem[0];
    }

    iterator end() {
        return &elem[0] + SZ;
    }

    typedef const T* const_iterator;

    const_iterator cbegin() const { return &elem[0]; }

    const T* cend() const { return &elem[0] + SZ; }
};