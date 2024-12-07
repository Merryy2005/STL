#include <iostream>
#include <vector>

namespace mystl
{
    template<typename InputIt, typename UnaryPred>
    InputIt find_if(InputIt first, InputIt last, UnaryPred p)
    {
        for(;first != last ; ++first)
        {
            if(p(*first)) return first;
        }
        return last;
    }
}

int main()
{
    std::vector<int> v{1,2,3,4,5};
    auto it = mystl::find_if(v.begin(), v.end(), [](const int& el) -> bool {return el >= 4;});
    if(it != v.end())
    {
        std::cout << "Found first element at pos " << (it - v.begin()) << std::endl;
    }
    else
    {
        std::cout << "None" << std::endl;
    }
    return 0;
}