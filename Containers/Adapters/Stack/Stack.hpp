#ifndef STACK_H
#define STACK_H

#include "C:\STL\Containers\Sequence\Vector\Vector.hpp"

namespace mystl
{
    template<typename T>
    class Stack : private Vector<T>
    {
        public:
            Stack();
            Stack(std::size_t);
            Stack(const Stack&);
            Stack(Stack&&) noexcept;
            Stack& operator= (const Stack&);
            Stack& operator= (Stack&&) noexcept;
            void push(const T& value);
            void pop();
            T& top();
            const T& top() const;
            bool empty() const;
            std::size_t size() const;
            void print() const;
    };
}

template<typename T>
mystl::Stack<T>::Stack() : Vector<T>() {}

template<typename T>
mystl::Stack<T>::Stack(std::size_t count) : mystl::Vector<T>(count) {}

template<typename T>
mystl::Stack<T>::Stack(const Stack& other) : mystl::Vector<T>(other) {}

template<typename T>
mystl::Stack<T>::Stack(Stack&& other) noexcept : Vector<T>(std::move(other)) {}

template<typename T>
mystl::Stack<T>& mystl::Stack<T>::operator=(const Stack& other)
{
    if (this != &other)
    {
        Vector<T>::operator=(other);
    }
    return *this;
}

template<typename T>
mystl::Stack<T>& mystl::Stack<T>::operator=(Stack&& other) noexcept
{
    if (this != &other)
    {
        Vector<T>::operator=(std::move(other));
    }
    return *this;
}

template<typename T>
void mystl::Stack<T>::push(const T& value)
{
    Vector<T>::push_back(value);
}

template<typename T>
void mystl::Stack<T>::pop()
{
    if (empty())
    {
        throw std::out_of_range("Stack is empty");
    }
    Vector<T>::pop_back();
}

template<typename T>
T& mystl::Stack<T>::top()
{
    if (empty())
    {
        throw std::out_of_range("Stack is empty");
    }
    return Vector<T>::back();
}

template<typename T>
const T& mystl::Stack<T>::top() const
{
    if (empty())
    {
        throw std::out_of_range("Stack is empty");
    }
    return Vector<T>::back();
}

template<typename T>
bool mystl::Stack<T>::empty() const
{
    return Vector<T>::empty();
}

template<typename T>
std::size_t mystl::Stack<T>::size() const
{
    return Vector<T>::size();
}

template<typename T>
void mystl::Stack<T>::print() const
{
    for (std::size_t i = 0; i < size(); ++i)
    {
        std::cout << Vector<T>::m_arr[i] << " ";
    }
    std::cout << std::endl;
}

#endif //STACK_H