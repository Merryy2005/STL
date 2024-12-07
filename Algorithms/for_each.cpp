#include <iostream>
#include <vector>

namespace mystl
{
    template<typename InputIt, typename UnaryFunc>
    UnaryFunc for_each(InputIt first, InputIt last, UnaryFunc f)
    {
        for(;first != last ; ++first)
        {
            f(*first);
        }
        return f;
    }
}

int main()
{
    std::vector<int> v{1,2,3,4,5};
    mystl::for_each(v.begin(), v.end(), [](const int& el) { std::cout << el << ' '; });
    std::cout << std::endl;
    return 0;
}