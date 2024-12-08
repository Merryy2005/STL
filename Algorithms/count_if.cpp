#include <iostream>
#include <vector>

namespace mystl
{
    template<typename InputIt, typename UnaryPred>
    typename std::iterator_traits<InputIt>::difference_type count_if(InputIt first, InputIt last, UnaryPred p)
    {
       typename std::iterator_traits<InputIt>::difference_type res = 0;
       for(; first != last ; ++first)
       {
            res += static_cast<int>(p(*first));
       }
       return res;
    }
}

int main()
{
    std::vector<int> v{1, 2, 3, 4, 5, 5, 2, 2, 1};
    std::cout << "Count of even numbers is " << mystl::count_if(v.begin() , v.end() , [](const int& a) -> bool{return a%2 == 0;}) << std::endl;
    std::cout << "Count of odd numbers is " << mystl::count_if(v.begin() , v.end() , [](const int& a) -> bool{return a%2 == 1;}) << std::endl;
    return 0;
}
