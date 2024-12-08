#include <iostream>
#include <vector>

namespace mystl
{
    template<typename ForwardIt>
    ForwardIt adjacent_find(ForwardIt first, ForwardIt last)
    {
        if(first == last) return last;
        auto it1 = first;
        auto it2 = first;
        ++it2;
        for(;it2 != last ; ++it1 , ++it2)
        {
            if(*it1 == *it2)
            {
                return it1;
            }
        }
        return last;
    }

    template<typename ForwardIt, typename BinaryPred>
    ForwardIt adjacent_find(ForwardIt first, ForwardIt last, BinaryPred p)
    {
        if(first == last) return last;
        auto it1 = first;
        auto it2 = first;
        ++it2;
        for(;it2 != last ; ++it1 , ++it2)
        {
            if(p(*it1 , *it2))
            {
                return it1;
            }
        }
        return last;
    }
}

int main()
{
    std::vector<int> v{1, 2, 2, 3, 4, 5, 5};
    auto it = mystl::adjacent_find(v.begin(), v.end());
    if(it != v.end())
    {
        std::cout << "Found the first adjacent pair at pos " << (it - v.begin()) << std::endl;
    }
    else
    {
        std::cout << "Didn't find adjacent pair" << std::endl;
    }
    it = mystl::adjacent_find(v.begin(), v.end() , [](const int& a , const int& b) -> bool{return (a+b)%2 == 0;});
    if(it != v.end())
    {
        std::cout << "Found the first adjacent pair at pos " << (it - v.begin()) << std::endl;
    }
    else
    {
        std::cout << "Didn't find adjacent pair" << std::endl;
    }
    return 0;
}
