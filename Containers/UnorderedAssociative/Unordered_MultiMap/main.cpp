#include <iostream>
#include "Unordered_MultiMap.hpp"

int main()
{
    mystl::Unordered_MultiMap<int, std::string> myMap;
    myMap.insert(1, "one");
    myMap.insert(2, "two");
    myMap.insert(1, "mek");
    myMap.emplace(3, "three");
    myMap.print();
    std::cout << myMap.contains(1) << std::endl;
    std::cout << myMap.contains(4) << std::endl;
    std::cout << myMap.count(1) << std::endl;
    std::cout << myMap.count(4) << std::endl;
    std::cout << myMap.count(3) << std::endl;
    myMap.erase(1);
    std::cout << myMap.size() << std::endl;
    myMap.print();
    myMap.clear();
    std::cout << "Size after clearing: " << myMap.size() << std::endl;
    return 0;
}
