#include "Map.hpp"
#include <string>

int main() 
{
    mystl::Map<int, std::string> myMap;
    myMap.insert(1, "One");
    myMap.insert(2, "Two");
    myMap.insert(3, "Three");
    std::cout << "Key 1: " << myMap[1] << std::endl;
    std::cout << "Key 2: " << myMap[2] << std::endl;
    try 
    {
        std::cout << "Key 3: " << myMap.at(3) << std::endl;
        std::cout << "Key 4: " << myMap.at(4) << std::endl;
    } 
    catch (const std::out_of_range& e) 
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    myMap.emplace(4, "Four");
    myMap.emplace(5, "Five");
    myMap.print();
    std::cout << "myMap size: " << myMap.size() << std::endl;
    if (myMap.empty()) 
    {
        std::cout << "myMap is empty" << std::endl;
    }
    else 
    {
        std::cout << "myMap is not empty" << std::endl;
    }
    for (auto it = myMap.begin(); it != myMap.end(); it = it->right) 
    {
        std::cout << "Key: " << it->key << ", Value: " << it->value[0] << std::endl;
    }
    myMap.erase(2);
    myMap.print();
    myMap.clear();
    std::cout << "myMap size after clear: " << myMap.size() << std::endl;
    return 0;
}
