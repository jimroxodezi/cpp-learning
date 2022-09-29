#include <iostream>


void copy_fct() {
    int v1[10] = {0,1,2,3,4,5,6,7,8,9};

    int v2[10];

    for (auto i = 0; i != 10; ++i)
        v2[i] = v1[i];

    for (auto &x : v2)
        std::cout << x << " ";

    std::cout<<std::endl; 
}

int count_x_cpp(const std::string ss, char x) {
    
    int count = 0;
    for (auto &i : ss) {
        if (i == x) ++count;
    }

    return count;
}

int count_x_c(const char *p, char x) {

    if (p == nullptr) return 0;
    int count = 0;
    for(; *p != 0; ++p) {   // if the value at p[i] is not null-terminated
        if (*p == x) ++count;
    }
    return count;
}

int main(){
    int i = 7.2;    // implicit conversion from double to int

    // int j{7.2}; // error: narrowing conversion from double to int

    // std::cout << i << j <<'\n';
    // copy_fct();
    char mystring[] = "Bob and Alice are like Romeo and Juliet, but for CS";
    std::cout << count_x_c(mystring, 'i') <<'\n';

    std::string str = "Bob and Alice are like Romeo and Juliet, but for CS";
    std::cout << count_x_cpp(str, 'o') <<'\n';

}
