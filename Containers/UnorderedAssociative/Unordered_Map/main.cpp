#include <iostream>
#include "Unordered_Map.hpp"

int main() {
    mystl::Unordered_Map<int, std::string> myMap;
    myMap.insert(1, "One");
    myMap.insert(2, "Two");
    myMap.insert(3, "Three");
    myMap[4] = "Four";
    myMap.print();
    std::cout <<  myMap.contains(1) << std::endl;
    std::cout << myMap.contains(5) << std::endl;
    myMap.erase(2);
    std::cout << myMap.contains(2) << std::endl;
    myMap.print();
    std::cout << myMap.size() << std::endl;
    std::cout << myMap.empty() << std::endl;
    myMap.clear();
    std::cout << myMap.size() << std::endl;
    std::cout << myMap.empty() << std::endl;
    return 0;
}
