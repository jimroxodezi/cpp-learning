#include <iostream>
#include <vector>
#include <numeric>


template<typename Iter, typename Val>
Val acc(Iter first, Iter last, Val res){
    for (auto &i = first; i != last; ++i) { // first, last are pointers
        res += *i;
    }
    return res;
}

template <typename T>
double mean(const std::vector<T> &v){
    if (v.size() == 0) {
        throw std::overflow_error("Cannot divide by zero");
    }

    double sum = acc(v.begin(), v.end(), 0.0);
    return sum/v.size();
}

int main(){

    std::vector<double> v = {1.5, 2.5, 3.5, 4.5, 5.5};

    // double sum = std::accumulate(v.begin(), v.end(), 0.0);
    double sum = acc(v.begin(), v.end(), 0.0);
    double avg = mean(v);

    std::cout << sum << "\n";
    std::cout << avg << std::endl;

    return 0;
}