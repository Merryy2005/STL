#include <iostream>
#include <algorithm>
#include <vector>
#include <list>


void print(std::vector<int>& v)
{
    for(int i = 0 ; i < v.size() ; i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

void print(std::list<int>& l)
{
    for (std::list<int>::iterator it = l.begin(); it != l.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}


int main()
{
    std::vector<int> v{5, 2, 4, 2, -1};
    print(v);
    std::sort(v.begin() , v.end());
    print(v);
    std::list<int> l{10,2,1,20,8};
    print(l);
    l.sort();//can't use std::sort with list
    print(l);
    return 0;
}