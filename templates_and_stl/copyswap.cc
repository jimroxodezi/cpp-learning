#include <iostream>
#include <vector>


template <typename T>
void print_vector(const std::vector<T> &v) {
    for (auto i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

template <typename IIter, typename OIter>
OIter cpy(IIter first, IIter last, OIter res) {
    // for (; first != last; ++first, ++res){
    //     *res = *first;
    // }

    // return res;

    // do
    // {
    //     *res = *first;
    //     ++res, ++first;
    // } while (first != last);
    
    // return res;

    while (first != last)
    {
        *res = *first;
        ++res, ++first;
    }
    return res;
}

int main(){

    std::vector<double> q = {11.2, 23.43, 23.45, 45.23, 12.5};
    std::vector<double> r(4);
    // r.reserve(q.size()); // doesn't work...!

    print_vector(q);
    print_vector(r);

    // std::copy(q.begin(), q.end(), r.begin());
    cpy(q.begin(), q.end(), r.begin());
    
    print_vector(q);
    print_vector(r);
    
    return 0;
}