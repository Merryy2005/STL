#include <iostream>
#include "Queue.hpp"

int main()
{
    mystl::Queue<int> myQueue;
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    myQueue.print();
    std::cout << myQueue.front() << std::endl;
    std::cout << myQueue.back() << std::endl;
    myQueue.pop();
    myQueue.print();
    return 0;
}
