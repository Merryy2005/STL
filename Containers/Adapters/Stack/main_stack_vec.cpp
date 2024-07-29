#include "Stack_Vec.h"

int main()
{
    mystl::stack<int> myStack;
    myStack.print();
    std::cout << (myStack.empty() ? "Stack is empty" : "Stack is not empty") << std::endl;
    myStack.push(5);
    myStack.push(6);
    myStack.push(7);
    myStack.push(8);
    myStack.push(9);
    myStack.print();
    myStack.pop();
    myStack.print();
    std::cout << (myStack.empty() ? "Stack is empty" : "Stack is not empty") << std::endl;
    std::cout << "Size = " << myStack.size() << std::endl;
    std::cout << "Top element : " << myStack.top() << std::endl;
    return 0;
}