#include <iostream>
#include <vector>

namespace mystl
{
    template<typename InputIt, typename UnaryPred>
    bool all_of(InputIt first, InputIt last, UnaryPred p)
    {
        for(;first != last ; ++first)
        {
            if(!p(*first)) return false;
        }
        return true;
    }
}

int main()
{
    std::vector<int> v{1,2,3,4,5};
    if(mystl::all_of(v.begin(), v.end(), [](const int& el) -> bool {return el <= 5;}))
    {
        std::cout << "All elements are equal or smaller than 5" << std::endl;
    }
    else
    {
        std::cout << "Not all elements are equal or smaller than 5" << std::endl;
    }
    return 0;
}