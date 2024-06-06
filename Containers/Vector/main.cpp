#include "vector.h"

int main()
{
    mystl::vector<int> v(10);
    std::cout << v;
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
    std::cout << v;
    v.pop_back();
    std::cout << v;
    v.pop_front();
    std::cout << v;
    v.insert(2 , 20);
    std::cout << v;
    v[7] = 9;
    std::cout << v;
    mystl::vector<std::string> vec1{"hi" , "hello" , "goodbye"};
    std::cout << vec1;
}