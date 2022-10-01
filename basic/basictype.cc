#include <iostream>

int main(){
    int i = 42;

    const int* p = &i;  // pointer to const
    // int const* p = &i;  // same as above

    int* const p = &i;  // const pointer 

    const int* const p = &i;    // const pointer to const
    // int const* const p = &i;    // same as above

    int j = 50;

    int& r = j; // reference

    const int& r = j;   // reference to const 

    return 0;
}