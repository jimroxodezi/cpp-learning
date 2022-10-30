#include <iostream>
#include <cstdint>


int main(void) {
    std::cout << "===============signed type===========\n";
    std::cout << sizeof(int8_t) << '\n';
    std::cout << sizeof(int16_t) << '\n';
    std::cout << sizeof(int32_t) << '\n';
    std::cout << sizeof(int64_t) << '\n';

    std::cout << "===============usigned type===========\n";
    std::cout << sizeof(uint8_t) << '\n';   // same as signed
    std::cout << sizeof(uint16_t) << '\n';
    std::cout << sizeof(uint32_t) << '\n';
    std::cout << sizeof(uint64_t) << '\n';

    std::cout << "===============int============\n";
    std::cout << sizeof(short int) << '\n';
    std::cout << sizeof(long int) << '\n';
    std::cout << sizeof(unsigned long) << '\n';
    std::cout << sizeof(uintmax_t) << '\n';
    // std::cout << sizeof() << '\n';

    std::cout << "===============macros============\n";
    std::cout << UINT8_MAX << '\n';
    std::cout << UINT16_MAX << '\n';
    std::cout << UINT32_MAX << '\n';
    std::cout << UINT64_MAX << '\n';

    std::cout << "=============signed macros==========\n";
    std::cout << INT8_MAX << '\n';
    std::cout << INT16_MAX << '\n';
    std::cout << INT32_MAX << '\n';
    std::cout << INT64_MAX << '\n';
    std::cout << INT8_MIN << '\n';
    std::cout << INT16_MIN << '\n';
    std::cout << INT32_MIN << '\n';
    std::cout << INT64_MIN << '\n';
    std::cout << UINTPTR_MAX << '\n';
   
}