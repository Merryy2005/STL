#include <iostream>
#include "Stack.hpp"

int main()
{
    mystl::Stack<int> myStack;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.print();
    std::cout << myStack.top() << std::endl;
    myStack.pop();
    myStack.print();
    return 0;
}
