#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>

namespace mystl
{
    template<typename T>
    class Deque
    {
        private:
            T* m_arr;
            std::size_t m_cap;
            std::size_t frontIndex;
            std::size_t backIndex;
            std::size_t m_size;
            void resize(std::size_t);
        public:
            Deque();
            bool empty() const;
            std::size_t size() const;
            void push_back(const T&);
            void push_front(const T&);
            void pop_back();
            void pop_front();
            T& front();
            const T& front() const;
            T& back();
            const T& back() const;
            T& at(std::size_t);
            const T& at(std::size_t) const;
            T& operator[](std::size_t);
            const T& operator[](std::size_t) const;
            ~Deque();
    };
}

template<typename T>
mystl::Deque<T>::Deque() : m_arr(new T[1]), m_cap(1), frontIndex(0), backIndex(0), m_size(0) {}

template<typename T>
bool mystl::Deque<T>::empty() const 
{
    return m_size == 0;
}

template<typename T>
std::size_t mystl::Deque<T>::size() const 
{
    return m_size;
}

template<typename T>
void mystl::Deque<T>::resize(std::size_t new_cap) 
{
    T* tmp = new T[new_cap];
    std::size_t j = 0;
    for (std::size_t i = frontIndex; i < frontIndex + m_size; i++) 
    {
        tmp[j++] = m_arr[i % m_cap];
    }
    delete[] m_arr;
    m_arr = tmp;
    m_cap = new_cap;
    frontIndex = 0;
    backIndex = m_size;
}

template<typename T>
void mystl::Deque<T>::push_back(const T& val) 
{
    if (m_size == m_cap) 
    {
        resize(m_cap * 2);
    }
    m_arr[backIndex] = val;
    backIndex = (backIndex + 1) % m_cap;
    m_size++;
}

template<typename T>
void mystl::Deque<T>::push_front(const T& val) 
{
    if (m_size == m_cap) 
    {
        resize(m_cap * 2);
    }
    frontIndex = (frontIndex == 0 ? m_cap - 1 : frontIndex - 1);
    m_arr[frontIndex] = val;
    m_size++;
}

template<typename T>
void mystl::Deque<T>::pop_back() 
{
    if (empty()) 
    {
        throw std::out_of_range("Deque is empty");
    }
    backIndex = (backIndex == 0 ? m_cap - 1 : backIndex - 1);
    m_size--;
}

template<typename T>
void mystl::Deque<T>::pop_front() 
{
    if (empty()) 
    {
        throw std::out_of_range("Deque is empty");
    }
    frontIndex = (frontIndex + 1) % m_cap;
    m_size--;
}

template<typename T>
T& mystl::Deque<T>::front() 
{
    if (empty()) 
    {
        throw std::out_of_range("Deque is empty");
    }
    return m_arr[frontIndex];
}

template<typename T>
const T& mystl::Deque<T>::front() const 
{
    if (empty()) 
    {
        throw std::out_of_range("Deque is empty");
    }
    return m_arr[frontIndex];
}

template<typename T>
T& mystl::Deque<T>::back() 
{
    if (empty()) 
    {
        throw std::out_of_range("Deque is empty");
    }
    return m_arr[(backIndex == 0 ? m_cap : backIndex) - 1];
}

template<typename T>
const T& mystl::Deque<T>::back() const 
{
    if (empty()) 
    {
        throw std::out_of_range("Deque is empty");
    }
    return m_arr[(backIndex == 0 ? m_cap : backIndex) - 1];
}

template<typename T>
T& mystl::Deque<T>::operator[](std::size_t pos)
{
    return m_arr[(frontIndex + pos) % m_cap];
}

template<typename T>
const T& mystl::Deque<T>::operator[](std::size_t pos) const
{
    return m_arr[(frontIndex + pos) % m_cap];
}

template <typename T>
T& mystl::Deque<T>::at(std::size_t pos) 
{
    if (pos >= m_size) 
    {
        throw std::out_of_range("Index out of range");
    }
    return m_arr[(frontIndex + pos) % m_cap];
}

template <typename T>
const T& mystl::Deque<T>::at(std::size_t pos) const 
{
    if (pos >= m_size) 
    {
        throw std::out_of_range("Index out of range");
    }
    return m_arr[(frontIndex + pos) % m_cap];
}

template<typename T>
mystl::Deque<T>::~Deque() 
{
    delete[] m_arr;
}

#endif // DEQUE_H
