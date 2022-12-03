#include <vector>
#include <concepts>
#include <iostream>
#include <iterator>


// std::bidirectional_iterator is a concept from the standard library.
void up_down(std::bidirectional_iterator auto begin, std::bidirectional_iterator auto end)
{
    std::ostream_iterator<int> cout_it(std::cout, " , ");
    std::copy(begin, end, cout_it);     // makes sense
    std::copy(std::make_reverse_iterator(end-1), std::make_reverse_iterator(begin), cout_it); // makes sense
}

int main(void){
    std::vector<int> vec{1,2,3,4,5};
    up_down(vec.begin(), vec.end());

    std::cout << std::endl;
}