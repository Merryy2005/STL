#include <iostream>
#include <vector>

namespace mystl
{
    template<typename ForwardIt1, typename ForwardIt2>
    ForwardIt1 find_end(ForwardIt1 first, ForwardIt1 last, ForwardIt2 s_first, ForwardIt2 s_last)
    {
        ForwardIt1 ans = last;
        size_t sz2 = std::distance(s_first, s_last);
        while (first != last)
        {
            ForwardIt1 start1 = first;
            ForwardIt2 start2 = s_first;
            size_t remaining = std::distance(first, last);
            if (remaining < sz2) break;
            while (start2 != s_last && *start1 == *start2)
            {
                ++start1;
                ++start2;
            }
            if (start2 == s_last)
            {
                ans = first;
            }
            ++first;
        }
        return ans;
    }
}

int main()
{
    std::vector<int> v1{4, 5, 1, 2, 3, 4, 5};
    std::vector<int> v2{4, 5};
    auto it = mystl::find_end(v1.begin(), v1.end(), v2.begin(), v2.end());
    if(it != v1.end())
    {
        std::cout << "Found the last occurrence at pos " << (it - v1.begin()) << std::endl;
    }
    else
    {
        std::cout << "Don't intersect" << std::endl;
    }
    return 0;
}
