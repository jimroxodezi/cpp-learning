#include <iostream>
#include <unordered_map>
#include <unordered_set> 
#include <vector>

/*
* C++ 11 Unordered set/multiset, unordered map/multimap
* These are hashtables. Order of elements is undefined.
*/

int main() {

    /*
    * unordered set
    */

    std::unordered_set<std::string> my_set = {"red", "green", "blue"};
    std::unordered_set<std::string>::const_iterator itr = my_set.find("green");

    if (itr != my_set.end())    // check is important. If element is not found
        std::cout << *itr << '\n';  // iterator points to end. 
    
    my_set.insert("yellow");

    std::vector<std::string> vec = {"purple", "pink"};
    my_set.insert(vec.begin(), vec.end());

    for (auto it : my_set) std::cout << it << " ";
    std::cout<<std::endl;

    // Hash Table specific APIs
    std::cout << "Load factor = " << my_set.load_factor() << std::endl;
    std::string x = "red";

    std::cout << x << " is in bucket #" <<my_set.bucket(x)<<std::endl;
    std::cout << "Total buckets #" << my_set.bucket_count() << std::endl;

    // unordered multiset: unordered set that allows duplicate keys
    // unordered map: unordered set of pairs
    // unordered multimap: unordered mapo that allows duplicate keys

    // Hash collision causes degrade in performance. Hash collision means
    // many elements are inserted in the same bucket.

    return 0;
}