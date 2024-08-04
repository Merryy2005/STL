#include "Unordered_MultiSet.hpp"
#include <iostream>

int main()
{
    mystl::Unordered_MultiSet<int> set1;
    std::cout << set1.size() << std::endl;
    set1.print();
    set1.insert(1);
    set1.insert(2);
    set1.insert(3);
    set1.insert(2);
    set1.print();
    mystl::Unordered_MultiSet<int> set2(set1);
    set2.print();
    std::cout << set2.contains(2) << std::endl;
    std::cout << set2.count(2) << std::endl;
    std::cout << set2.size() << std::endl;
    set2.erase(2);
    set2.print();
    std::cout << set2.size() << std::endl;
    set2.erase(3);
    set2.erase(1);
    std::cout << set2.empty() << std::endl;
    return 0;
}
