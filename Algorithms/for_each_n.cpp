#include <iostream>
#include <vector>

namespace mystl
{
    template<typename InputIt, typename Size, typename UnaryFunc>
    InputIt for_each_n(InputIt first, Size n, UnaryFunc f)
    {
        for(Size i = 0 ; i < n ; ++i)
        {
            f(*first);
            ++first;
        }
        return first;
    }
}

int main()
{
    std::vector<int> v{1,2,3,4,5};
    mystl::for_each_n(v.begin(), 3, [](const int& el) { std::cout << el << ' '; });
    std::cout << std::endl;
    return 0;
}