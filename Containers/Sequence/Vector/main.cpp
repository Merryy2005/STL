#include "Vector.hpp"
#include <algorithm>

int main()
{
    mystl::Vector<int> v(10);
    for(std::size_t i = 0 ; i < v.size() ; i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "v.size() = " << v.size() << std::endl;
    v.reserve(20);
    std::cout << "v.size() = " << v.size() << std::endl;
    v.resize(6);
    std::cout << "v.size() = " << v.size() << std::endl;
    for(auto it = v.begin() ; it != v.end() ; ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    v.push_back(5);
    v.push_back(5);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    v.push_front(10);
    v.push_front(11);
    v.push_front(13);
    v.push_front(5);
    v.push_front(7);
    v.push_front(8);
    for(std::size_t i = 0 ; i < v.size() ; i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    v.pop_back();
    for(std::size_t i = 0 ; i < v.size() ; i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    v.pop_front();
    for(std::size_t i = 0 ; i < v.size() ; i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    v.insert(2 , 20);
    for(std::size_t i = 0 ; i < v.size() ; i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    v[7] = 9;
    for(std::size_t i = 0 ; i < v.size() ; i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    mystl::Vector<std::string> vec1{"hi" , "hello" , "goodbye"};
    for(std::size_t i = 0 ; i < vec1.size() ; i++)
    {
        std::cout << vec1[i] << " ";
    }
    std::cout << std::endl;
}