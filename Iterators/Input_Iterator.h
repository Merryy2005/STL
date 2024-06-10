#ifndef INPUTITERATOR_H
#define INPUTITERATOR_H

#include <iostream>

namespace mystl
{
    template<typename T> 
    class List;

    template<typename T> 
    class Node;

    template<typename T>
    class InputIterator
    {
        private:
            typename mystl::List<T>::Node* m_ptr;
        public:
            InputIterator();
            InputIterator(typename mystl::List<T>::Node*);
            InputIterator(const InputIterator&);
            T& operator*() const;
            T* operator->() const;
            InputIterator& operator=(const InputIterator&);
            InputIterator& operator++();
            InputIterator operator++(int);
            bool operator==(const InputIterator&) const;
            bool operator!=(const InputIterator&) const;
    };
}

template<typename T>
mystl::InputIterator<T>::InputIterator() : m_ptr(nullptr)
{
}

template<typename T>
mystl::InputIterator<T>::InputIterator(typename mystl::List<T>::Node* ptr) : m_ptr(ptr)
{
}

template<typename T>
mystl::InputIterator<T>::InputIterator(const InputIterator& other) : m_ptr(other.m_ptr)
{
}

template<typename T>
T& mystl::InputIterator<T>::operator*() const
{
    return m_ptr->val;
}

template<typename T>
T* mystl::InputIterator<T>::operator->() const
{
    return &(m_ptr->val);
}

template<typename T>
mystl::InputIterator<T>& mystl::InputIterator<T>::operator=(const InputIterator& other)
{
    if (this != &other)
    {
        m_ptr = other.m_ptr;
    }
    return *this;
}

template<typename T>
mystl::InputIterator<T>& mystl::InputIterator<T>::operator++()
{
    if (m_ptr)
    {
        m_ptr = m_ptr->next;
    }
    return *this;
}

template<typename T>
mystl::InputIterator<T> mystl::InputIterator<T>::operator++(int)
{
    InputIterator tmp(*this);  
    ++(*this); 
    return tmp; 
}

template<typename T>
bool mystl::InputIterator<T>::operator==(const InputIterator& other) const
{
    return (m_ptr == other.m_ptr);
}

template<typename T>
bool mystl::InputIterator<T>::operator!=(const InputIterator& other) const
{
    return (m_ptr != other.m_ptr);
}

#endif // INPUTITERATOR_H
