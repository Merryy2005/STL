#include <iostream>
#include "Set.hpp"

int main() 
{
    mystl::Set<int> mySet;
    mySet.insert(20);
    mySet.insert(10);
    mySet.insert(30);
    mySet.insert(50);
    mySet.insert(40);
    mySet.insert(50);
    mySet.print();
    std::cout << "Is the set empty? " << (mySet.empty() ? "Yes" : "No") << std::endl;
    std::cout << "Size of the set: " << mySet.size() << std::endl;
    mySet.erase(30);
    std::cout << "\nAfter erasing 30:\n";
    mySet.print();
    std::cout << "Is the set empty? " << (mySet.empty() ? "Yes" : "No") << std::endl;
    std::cout << "Size of the set: " << mySet.size() << std::endl;
    std::cout << "\nContains 5: " << (mySet.contains(5) ? "Yes" : "No") << std::endl;
    std::cout << "Contains 20: " << (mySet.contains(20) ? "Yes" : "No") << std::endl;
    int keys[] = {20, 5, 60};
    for (int key : keys) 
    {
        auto lb = mySet.lower_bound(key);
        std::cout << "Lower bound of " << key << ": " << (lb ? std::to_string(lb->key) : "not found") << std::endl;
        
        auto ub = mySet.upper_bound(key);
        std::cout << "Upper bound of " << key << ": " << (ub ? std::to_string(ub->key) : "not found") << std::endl;
    }
    return 0;
}
