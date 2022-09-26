#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <deque>
#include <unordered_map>    //unordered map and multimap
#include <unordered_set>    // unordered set and multiset
#include <algorithm>
#include <numeric>  // some numeric algorithms
#include <functional>
#include <iterator> // iterators related stuffs

using namespace std;

int main() {

    // // vector is a dynamic array that grows in one direction
    // vector<int> vec;
    // vec.push_back(4);
    // vec.push_back(1);
    // vec.push_back(8);

    // cout << vec[2] << endl; // no range check
    // cout << vec.at(2); // automatically adds a newline. has range check

    // for (int i; i < vec.size(); i++) {
    //     cout << vec[i] << " ";
    // }
    // cout<<endl;

    // // recommended and faster way of traversing stl containers
    // for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
    //     cout << *itr << " ";
    // }
    // cout<<endl;

    // for (auto it : vec) {
    //     cout << it << " ";
    // }
    // cout<<endl;

    // // vector is a dynamically allocated contiguous array of memory
    // int* p = &vec[0];

    // deque<int> deq = {4,6,7};
    // deq.push_back(3);
    // deq.push_front(2);

    // cout << deq[1] << endl;

    // for (auto &i : deq) cout << i << " ";
    // cout<<endl;

    // // std::list is double linked list with fast inert/remove at any place O(1)
    // // std::list has a slow search O(n) but much slower than a vector or deque
    // // due to the problem of locality. each element in std::list is stored in a 
    // // different part of memory. Hence a lot of cache misses
    // //  std::list consumes more memory, hence more cache misses and page faults.
    // // a power feature of std::list<T> however is the splice function
    // list<int> lst = {5,2,9};
    // lst.push_back(6);   // lst: {5,2,9,6}
    // lst.push_front(4);  // lst: {4,5,2,9,6}

    // for (auto i : lst) cout << i << " ";
    // cout<<endl;

    // auto itr = find(lst.begin(), lst.end(), 2); // itr -> 2
    // cout << *itr << endl;
    // lst.insert(itr, {8});   // O(1) insertion

    // for (auto i : lst) cout << i << " ";
    // cout<<endl;

    // itr++;  // itr -> 9
    // lst.erase(itr); // remove 9. O(1) deletion
    // for (auto i : lst) cout << i << " ";
    // cout<<endl; 


    // std::foraward_list is just like std::list except that it only has forward pointer
    // which means it can only be traversed  from begin to end and not the other way round


    // std::array<T, size> is a thin abstraction on the native array. It has a fixed size
    // and it's size is part of it's type. It has the usual container functions like
    // size(), swap(), begin(), end(), etc.
    return 0;
}