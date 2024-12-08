#include <iostream>
#include <vector>

namespace mystl
{
    template<typename InputIt, typename ForwardIt>
    InputIt find_first_of(InputIt first, InputIt last, ForwardIt s_first, ForwardIt s_last)
    {
        for(; first!=last ; ++first)
        {
            for(auto it = s_first ; it != s_last ; ++it)
            {
                if(*first == *it)
                {
                    return first;
                }
            }
        }
        return last;
    }
    
    template<typename InputIt, typename ForwardIt, typename BinaryPred>
    InputIt find_first_of(InputIt first, InputIt last, ForwardIt s_first, ForwardIt s_last, BinaryPred p)
    {
        for(; first!=last ; ++first)
        {
            for(auto it = s_first ; it != s_last ; ++it)
            {
                if(p(*first , *it))
                {
                    return first;
                }
            }
        }
        return last;
    }
}

int main()
{
    std::vector<int> v1{1, 2, 3, 4, 5};
    std::vector<int> v2{5, 4};
    auto it = mystl::find_first_of(v1.begin(), v1.end(), v2.begin(), v2.end());
    if(it != v1.end())
    {
        std::cout << "Found the first occurrence at pos " << (it - v1.begin()) << std::endl;
    }
    else
    {
        std::cout << "Didn't find occurence" << std::endl;
    }
    it = mystl::find_first_of(v1.begin(), v1.end(), v2.begin(), v2.end() , [](const int& a , const int& b) -> bool{return (a+b) == 7;});
    if(it != v1.end())
    {
        std::cout << "Found the first occurrence at pos " << (it - v1.begin()) << std::endl;
    }
    else
    {
        std::cout << "Didn't find occurence" << std::endl;
    }
    return 0;
}
