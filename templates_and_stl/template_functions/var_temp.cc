#include <iostream>


void print(){ std::cout<<std::endl;}

template <typename T1, typename... OTHERS>
void print(T1 first, OTHERS... rest) {
    std::cout << first << ",";

    print(rest...);

}


int main(void) {
    print("jimrox",1,'3',"Odezi");

    return 0;
}