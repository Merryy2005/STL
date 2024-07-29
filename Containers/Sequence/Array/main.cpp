#include "Array.hpp"

int main()
{
    mystl::Array<int , 5> myarr = {1,2,3};
    for(std::size_t i = 0 ; i < 5 ; i++)
    {
        std::cout << myarr[i] << " ";
    }
    std::cout << std::endl;
    std::cout << myarr.at(4) << std::endl;
    std::cout << myarr[2] << std::endl;
    myarr[4] = 5;
    for(std::size_t i = 0 ; i < 5 ; i++)
    {
        std::cout << myarr[i] << " ";
    }
    std::cout << std::endl;
    mystl::Array<int , 5> myarr1 = {1,2,3,4,5};
    if(myarr > myarr1)
    {
        std::cout << "myarr > myarr1" << std::endl;
    }
    else
    {
        std::cout << "myarr < myarr1" << std::endl;
    }
    for(auto it = myarr1.rbegin() ; it != myarr1.rend() ; it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    myarr1.fill(3);
    for(auto it = myarr1.begin() ; it != myarr1.end() ; it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    myarr.swap(myarr1);
    for(auto it = myarr.begin() ; it != myarr.end() ; it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    for(auto it = myarr1.begin() ; it != myarr1.end() ; it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    mystl::Array<int , 5> myarr2(myarr);
    for(auto it = myarr2.begin() ; it != myarr2.end() ; it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    return 0;
}