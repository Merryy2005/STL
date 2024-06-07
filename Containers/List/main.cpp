#include "List.h"
int main()
{
    mystl::List<int> list;
    list.print();
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.print();
    list.push_front(6);
    list.push_front(7);
    list.push_front(8);
    list.print();
    list.pop_front();
    list.pop_front();
    list.print();
    list.pop_back();
    list.print();
    list.insert(2 , 8);
    list.print();
    list.insert(4, 10);
    list.print();
    list.insert(0 , -2);
    list.print();
    list.insert(8 , 20);
    list.print();
    std::cout << (list.hasLoop() ? "List has loop" : "List doesn't have loop")<< std::endl;
    list.reverseList();
    std::cout << "Reversed List : " << std::endl;
    list.print();
    std::cout << list.findNthlastElem(3) << std::endl;
    list.createLoop(2);
    list.print();
    std::cout << (list.hasLoop() ? "List has loop" : "List doesn't have loop") << std::endl;
    return 0;
}