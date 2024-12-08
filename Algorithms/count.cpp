#include <iostream>
#include <vector>

namespace mystl
{
    template<typename InputIt, typename T>
    typename std::iterator_traits<InputIt>::difference_type count(InputIt first, InputIt last, const T& value)
    {
       typename std::iterator_traits<InputIt>::difference_type res = 0;
       for(; first != last ; ++first)
       {
            res += (*first == value);
       }
       return res;
    }
}

int main()
{
    std::vector<int> v{1, 2, 3, 4, 5, 5, 2, 2, 1};
    for(int i = 0 ; i < 7 ; i++)
    {
        std::cout << "Count of " << i << " is " << mystl::count(v.begin() , v.end() , i) << std::endl;
    }
    return 0;
}
