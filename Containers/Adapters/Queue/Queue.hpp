#ifndef QUEUE_H
#define QUEUE_H

#include "C:\STL\Containers\Sequence\Vector\Vector.hpp"

namespace mystl
{
    template<typename T>
    class Queue
    {
        private:
            mystl::Vector<T> m_vector;
            std::size_t m_front;
            std::size_t m_back;
        public:
            Queue();
            Queue(const Queue&);
            Queue(Queue&&) noexcept;
            Queue& operator=(const Queue&);
            Queue& operator=(Queue&&) noexcept;
            void push(const T& value);
            void pop();
            T& front();
            const T& front() const;
            T& back();
            const T& back() const;
            bool empty() const;
            std::size_t size() const;
            void print() const;
    };
}

template<typename T>
mystl::Queue<T>::Queue() : m_vector(), m_front(0), m_back(0) {}

template<typename T>
mystl::Queue<T>::Queue(const Queue& other) : m_vector(other.m_vector), m_front(other.m_front), m_back(other.m_back) {}

template<typename T>
mystl::Queue<T>::Queue(Queue&& other) noexcept : m_vector(std::move(other.m_vector)), m_front(other.m_front), m_back(other.m_back)
{
    other.m_front = 0;
    other.m_back = 0;
}

template<typename T>
mystl::Queue<T>& mystl::Queue<T>::operator=(const Queue& other)
{
    if (this != &other)
    {
        m_vector = other.m_vector;
        m_front = other.m_front;
        m_back = other.m_back;
    }
    return *this;
}

template<typename T>
mystl::Queue<T>& mystl::Queue<T>::operator=(Queue&& other) noexcept
{
    if (this != &other)
    {
        m_vector = std::move(other.m_vector);
        m_front = other.m_front;
        m_back = other.m_back;
        other.m_front = 0;
        other.m_back = 0;
    }
    return *this;
}

template<typename T>
void mystl::Queue<T>::push(const T& value)
{
    if (m_back >= m_vector.size())
    {
        m_vector.push_back(value);
    }
    else
    {
        m_vector[m_back] = value;
    }
    ++m_back;
}

template<typename T>
void mystl::Queue<T>::pop()
{
    if (empty())
    {
        throw std::out_of_range("Queue is empty, can't pop");
    }
    m_front++;
    if (m_front == m_back)
    {
        m_front = 0;
        m_back = 0;
    }
}

template<typename T>
T& mystl::Queue<T>::front()
{
    if (empty())
    {
        throw std::out_of_range("Queue is empty, can't access front");
    }
    return m_vector[m_front];
}

template<typename T>
const T& mystl::Queue<T>::front() const
{
    if (empty())
    {
        throw std::out_of_range("Queue is empty, can't access front");
    }
    return m_vector[m_front];
}

template<typename T>
T& mystl::Queue<T>::back()
{
    if (empty())
    {
        throw std::out_of_range("Queue is empty, can't access back");
    }
    return m_vector[m_back - 1];
}

template<typename T>
const T& mystl::Queue<T>::back() const
{
    if (empty())
    {
        throw std::out_of_range("Queue is empty, can't access back");
    }
    return m_vector[m_back - 1];
}

template<typename T>
bool mystl::Queue<T>::empty() const
{
    return m_front == m_back;
}

template<typename T>
std::size_t mystl::Queue<T>::size() const
{
    return m_back - m_front;
}

template<typename T>
void mystl::Queue<T>::print() const
{
    for (std::size_t i = m_front; i < m_back; ++i)
    {
        std::cout << m_vector[i] << " ";
    }
    std::cout << std::endl;
}

#endif //QUEUE_H
