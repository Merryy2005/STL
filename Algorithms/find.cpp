#include <iostream>
#include <vector>

namespace mystl
{
    template<typename InputIt, typename T>
    InputIt find(InputIt first, InputIt last, const T& val)
    {
        for(;first != last ; ++first)
        {
            if(*first == val) return first;
        }
        return last;
    }
}

int main()
{
    std::vector<int> v{1,2,3,4,5};
    if(mystl::find(v.begin(), v.end(), 2) != v.end())
    {
        std::cout << "Found 2" << std::endl;
    }
    else
    {
        std::cout << "2 not found" << std::endl;
    }
    if(mystl::find(v.begin(), v.end(), 6) != v.end())
    {
        std::cout << "Found 6" << std::endl;
    }
    else
    {
        std::cout << "6 not found" << std::endl;
    }
    return 0;
}