#include "Deque.hpp"
#include <algorithm>

int main()
{
    mystl::Deque<int> d;
    d.push_back(1);
    d.push_back(2);
    d.push_front(3);
    d.push_front(4);
    for(int i = 0 ; i < d.size() ; i++)
    {
        std::cout << d[i] << " ";
    }
    std::cout << std::endl;
    d.pop_front();
    for(int i = 0 ; i < d.size() ; i++)
    {
        std::cout << d[i] << " ";
    }
    std::cout << std::endl;
    d.pop_back();
    for(int i = 0 ; i < d.size() ; i++)
    {
        std::cout << d[i] << " ";
    }
    std::cout << std::endl;
    std::cout << d.front() << std::endl;
    std::cout << d.back() << std::endl;
    d.pop_front();
    d.pop_back();
    std::cout << d.empty() << std::endl;
    return 0;
}