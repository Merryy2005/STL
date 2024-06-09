#include "List.h"
#include "C:/STL/Iterators/Input_Iterator.h"

template<typename Iterator>
void print(Iterator begin , Iterator end)
{
    for(Iterator it = begin ; it != end ; ++it)
    {
        std::cout << it->getValue() << " ";
    }
    std::cout << std::endl;
    return;
}

int main()
{
    mystl::List<int> list;
    print(list.begin() , list.end());
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    print(list.begin() , list.end());
    list.push_front(6);
    list.push_front(7);
    list.push_front(8);
    print(list.begin() , list.end());
    list.pop_front();
    list.pop_front();
    print(list.begin() , list.end());
    list.pop_back();
    print(list.begin() , list.end());
    list.insert(2 , 8);
    print(list.begin() , list.end());
    list.insert(4, 10);
    print(list.begin() , list.end());
    list.insert(0 , -2);
    print(list.begin() , list.end());
    list.insert(8 , 20);
    print(list.begin() , list.end());
    std::cout << (list.hasLoop() ? "List has loop" : "List doesn't have loop")<< std::endl;
    list.reverseList();
    std::cout << "Reversed List : " << std::endl;
    print(list.begin() , list.end());
    // std::cout << list.findNthlastElem(3) << std::endl;
    // list.createLoop(2);
    // print(list.begin() , list.end());
    // std::cout << (list.hasLoop() ? "List has loop" : "List doesn't have loop") << std::endl;
    return 0;
}