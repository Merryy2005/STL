#include "MultiMap.hpp"
#include <string>

int main() 
{
    mystl::MultiMap<int, std::string> myMultiMap;
    myMultiMap.insert(1, "One");
    myMultiMap.insert(1, "Mek");
    myMultiMap.insert(2, "Two");
    myMultiMap.insert(3, "Three");
    myMultiMap.insert(3, "Ereq");
    myMultiMap.print();
    std::cout << myMultiMap.count(2) << std::endl;
    std::cout << "Key 1 values: ";
    for (const auto& val : myMultiMap.find(1)->value) 
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    std::cout << "Key 3 values: ";
    for (const auto& val : myMultiMap.find(3)->value)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    for (auto it = myMultiMap.begin(); it != myMultiMap.end(); it = it->right) 
    {
        std::cout << "Key: " << it->key << " Values: ";
        for (const auto& val : it->value) 
        {
            std::cout << val << " ";
        }
        std::cout << "| ";
    }
    std::cout << std::endl;
    myMultiMap.erase(1);
    myMultiMap.print();       
    std::cout << "myMultiMap size: " << myMultiMap.size() << std::endl;
    myMultiMap.clear();
    std::cout << "myMultiMap size after clear: " << myMultiMap.size() << std::endl;
    return 0;
}
