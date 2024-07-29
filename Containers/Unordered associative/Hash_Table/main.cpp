#include "Hash_Table.hpp"
#include <iostream>

int main()
{
    mystl::HashMap<int, std::string> myMap;
    myMap.insert(1, "One");
    myMap.insert(2, "Two");
    myMap.insert(3, "Three");
    myMap.insert(4, "Four");
    std::cout << "Value for key 2: " << myMap.search(2) << std::endl;
    std::cout << "Value for key 5: " << myMap.search(5) << std::endl; // Missing
    myMap.remove(3);
    std::cout << "Elements:" << std::endl;
    for (int i = 1; i <= 4; ++i)
    {
        std::cout << "Key " << i << ": " << myMap.search(i) << std::endl;
    }
    return 0;
}
