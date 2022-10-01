#include <iostream>
#include <set>  // set and multiset
#include <map>  // map and multimap
#include <algorithm>

/*
    Associative containers are implemented with binary trees.
    They are always sorted. Their sorted order is always maintained
    after every insertion and deletion. No push_back() and push_front().
    Value of elements are read-only. Traversing is slow due to the 
    problem of locality.
*/


int main() {
    // std::set has no duplicates
    std::set<int> my_set;
    my_set.insert(3);
    my_set.insert(1);
    my_set.insert(7);
    my_set.insert(7);

    for (auto it : my_set) std::cout << it << " ";
    std::cout<<std::endl;

    std::set<int>::iterator it;
    it = my_set.find(7);

    // std::cout << *it << '\n';

    std::pair<std::set<int>::iterator, bool> ret;
    ret = my_set.insert(3);

    if (ret.second == false)
        it = ret.first;

    my_set.insert(9);
    for (auto it : my_set) std::cout << it << " ";
    std::cout<<std::endl;

    my_set.erase(it);
    for (auto it : my_set) std::cout << it << " ";
    std::cout<<std::endl;

    my_set.erase(7);
    for (auto it : my_set) std::cout << it << " ";
    std::cout<<std::endl;

    // multiset allows duplicate items
    std::multiset<int> myset;
    myset.insert(1);
    myset.insert(2);
    myset.insert(1);

    for (auto it : myset) std::cout << it << " ";
    std::cout<<std::endl;    


}

/*
    * Map and Multimap. They are not sorted but are arranged in key-value
    * pairs. Keys cannot be modified...only values can be modified
*/



// int main() {
//     /*
//     * std::map
//     *
//     * - No duplicate keys
//     */

//     std::map<char, int> my_map;
//     my_map.insert(std::pair<char,int>('a',100));
//     my_map.insert(std::make_pair('z',200));

//     std::map<char,int>::iterator it = my_map.begin();
//     my_map.insert(it, std::make_pair('b',300)); // "it" is a hint

//     it = my_map.find('b');

//     for (auto it = my_map.begin(); it != my_map.end(); ++it)
//     std::cout << it->first << " => " << it->second << std::endl;

//     std::cout << "==============multimap==============\n";

//     // a multimap allows duplicate keys.
//     std::multimap<char,int> mmap;
//     mmap.insert(std::make_pair('a',100));
//     mmap.insert(std::make_pair('a',200));

//     for (auto it = mmap.begin(); it != mmap.end(); ++it)
//     std::cout << it->first << " => " << it->second << std::endl;
// }