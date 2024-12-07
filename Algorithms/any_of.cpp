#include <iostream>
#include <vector>

namespace mystl
{
    template<typename InputIt, typename UnaryPred>
    bool any_of(InputIt first, InputIt last, UnaryPred p)
    {
        for(;first != last ; ++first)
        {
            if(p(*first)) return true;
        }
        return false;
    }
}

int main()
{
    std::vector<int> v{1,2,3,4,5};
    if(mystl::any_of(v.begin(), v.end(), [](const int& el) -> bool {return el > 2;}))
    {
        std::cout << "At least one of the elements is greater than 2" << std::endl;
    }
    else
    {
        std::cout << "None of the elements is greater than 2" << std::endl;
    }
    return 0;
}