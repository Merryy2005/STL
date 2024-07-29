#include "Multiset.hpp"

int main() 
{
    mystl::Multiset<int> myMultiset;
    myMultiset.insert(5);
    myMultiset.insert(3);
    myMultiset.insert(7);
    myMultiset.insert(3);  
    myMultiset.insert(5); 
    std::cout << "Multiset contents: ";
    myMultiset.print();
    std::cout << "Contains 5? " << (myMultiset.contains(5) ? "Yes" : "No") << std::endl;
    std::cout << "Contains 10? " << (myMultiset.contains(10) ? "Yes" : "No") << std::endl;
    std::cout << "Size of multiset: " << myMultiset.size() << std::endl;
    std::cout << "Count of 5: " << myMultiset.count(5) << std::endl;
    auto lb = myMultiset.lower_bound(5);
    auto ub = myMultiset.upper_bound(5);
    std::cout << "Lower bound for 5: " << (lb ? std::to_string(lb->key) : "None") << std::endl;
    std::cout << "Upper bound for 5: " << (ub ? std::to_string(ub->key) : "None") << std::endl;
    myMultiset.erase(5);
    std::cout << "Multiset contents after erasing 5:" << std::endl;
    myMultiset.print();
    std::cout << "Size of multiset after erasing 5: " << myMultiset.size() << std::endl;
    myMultiset.clear();
    std::cout << "Multiset contents after clearing:" << std::endl;
    myMultiset.print();
    return 0;
}
