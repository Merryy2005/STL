#ifndef STACK_H
#define STACK_H

#include <iostream>

namespace mystl
{
    template<typename T>
    class vector
    {
        protected:
            int m_size;
            int m_cap;
            T* m_arr;
        public:
            vector();
            vector(int);
            vector(const std::initializer_list<T>&);
            vector(const vector&);
            vector(vector&&);
            vector& operator= (const vector&);
            vector& operator= (vector&&);
            T operator[](int) const;
            T& operator[](int);
            int size() const;
            bool empty() const;
            void push_back(T);
            void pop_back();
            void push_front(T);
            void pop_front();
            void insert(int , T);
            void print() const;
            ~vector();
    };
    template<typename T>
    class stack : private vector<T>
    {
        public:
            stack();
            stack(int);
            stack(const stack&);
            stack& operator= (const stack&);
            T top() const;
            bool empty() const;
            int size() const;
            void push(T);
            void pop();
            void print() const;
            ~stack();
    };
}

template <typename T>
mystl::vector<T>::vector() : m_size(0) , m_cap(1) , m_arr(new T[m_cap])
{

}

template <typename T>
mystl::vector<T>::vector(int cap) : m_size(0) , m_cap(cap > 0 ? cap : 1) , m_arr(new T[cap])
{

}

template <typename T>
mystl::vector<T>::vector(const std::initializer_list<T>& list) : m_size(list.size()) , m_cap(2*list.size()) , m_arr(new T[2*list.size()]) 
{
    int i = 0;
    for (auto it = list.begin(); it != list.end(); it++) 
    {
        m_arr[i++] = *it;
    }
}

template <typename T>
mystl::vector<T>::vector(const vector<T>& other) : m_size(other.m_size) , m_cap(other.m_cap) , m_arr(new T[m_cap])
{
    for(int i = 0 ; i < m_size ; i++)
    {
        m_arr[i] = other.m_arr[i];
    }
}

template <typename T>
mystl::vector<T>::vector(vector<T>&& other) : m_size(other.m_size) , m_cap(other.m_cap) , m_arr(other.m_arr)
{
    other.m_size = 0;
    other.m_cap = 0;
    other.m_arr = nullptr;
}

template <typename T>
mystl::vector<T>& mystl::vector<T>::operator= (const mystl::vector<T>& other)
{
    if(this != &other)
    {
        delete[] m_arr;
        m_size = other.m_size;
        m_cap = other.m_cap;
        m_arr = new T[m_cap];
        for(int i = 0 ; i < m_size ; i++)
        {
            m_arr[i] = other.m_arr[i];
        }
    }
    return *this;
}

template <typename T>
mystl::vector<T>& mystl::vector<T>::operator= (mystl::vector<T>&& other)
{
    if(this != &other)
    {
        delete[] m_arr;
        m_size = other.m_size;
        m_cap = other.m_cap;
        m_arr = other.m_arr;
        other.m_arr = nullptr;
        other.m_size = 0;
        other.m_cap = 0;
    }
    return *this;
}

template <typename T>
T mystl::vector<T>::operator[](int ind) const
{
    if(ind < 0 || ind >= m_size)
    {
        throw std::out_of_range("This index is not valid.");
    }
    return m_arr[ind];
}

template <typename T>
T& mystl::vector<T>::operator[](int ind)
{
    if(ind < 0 || ind >= m_size)
    {
        throw std::out_of_range("This index is not valid.");
    }
    return m_arr[ind];
}

template <typename T>
int mystl::vector<T>::size() const
{
    return m_size;
}

template <typename T>
bool mystl::vector<T>::empty() const
{
    return m_size == 0;
}

template <typename T>
void mystl::vector<T>::push_back(T val)
{
    if(m_size == m_cap)
    {
        T* temp = new T[m_cap*2];
        for(int i = 0 ; i < m_size; i++)
        {
            temp[i] = m_arr[i];
        }
        delete[] m_arr;
        m_arr = temp;
        m_cap *= 2;
    }
    m_arr[m_size++] = val;
}

template <typename T>
void mystl::vector<T>::pop_back()
{
    if(m_size == 0)
    {
        throw std::out_of_range("Empty vector, can't call pop_back()");
    }
    else
    {
        m_arr[--m_size] = T();
    }
}

template <typename T>
void mystl::vector<T>::push_front(T val)
{
    if(m_size == m_cap)
    {
        T* temp = new T[m_cap*2];
        for(int i = 0 ; i < m_size; i++)
        {
            temp[i+1] = m_arr[i];
        }
        delete[] m_arr;
        m_arr = temp;
        m_cap *= 2;
    }
    else
    {
        for(int i = m_size ; i > 0 ; i--)
        {
            m_arr[i] = m_arr[i-1];
        }
    }
    m_arr[0] = val;
    m_size++;
}

template <typename T>
void mystl::vector<T>::pop_front()
{
    if(m_size == 0)
    {
        throw std::out_of_range("Empty vector, can't call pop_front()");
    }
    else
    {
        for(int i = 0 ; i < (m_size-1) ; i++)
        {
            m_arr[i] = m_arr[i+1];
        }
        m_arr[--m_size] = T();
    }
}

template <typename T>
void mystl::vector<T>::insert(int pos , T val)
{
    if(m_size == m_cap)
    {
        T* temp = new T[m_cap*2];
        for(int i = 0 ; i < m_size; i++)
        {
            temp[i] = m_arr[i];
        }
        delete[] m_arr;
        m_arr = temp;
        m_cap *= 2;
    }
    for(int i = m_size ; i > pos ; i--)
    {
        m_arr[i] = m_arr[i-1];
    }
    m_arr[pos] = val;
    m_size++;
}

template <typename T>
void mystl::vector<T>::print() const
{
    for (int i = 0; i < m_size; i++)
    {
        std::cout << m_arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
mystl::vector<T>::~vector()
{
    delete[] m_arr;
}

template <typename T>
mystl::stack<T>::stack() : vector<T>()
{

}

template <typename T>
mystl::stack<T>::stack(int cap) : vector<T>(cap)
{

} 

template <typename T>
mystl::stack<T>::stack(const stack& other) : vector<T>(other)
{

}

template <typename T>
mystl::stack<T>& mystl::stack<T>::operator= (const mystl::stack<T>& other)
{
    if(this != &other)
    {
        vector<T>::operator=(other);
    }
    return *this;
}

template <typename T>
T mystl::stack<T>::top() const
{
    if (this->m_size == 0)
    {
        std::cout << "Stack is empty, can't call top" << std::endl;
        return T();
    }
    else
    {
        return this->m_arr[this->m_size - 1];
    }
}

template <typename T>
bool mystl::stack<T>::empty() const
{
    return vector<T>::empty();
}

template <typename T>
int mystl::stack<T>::size() const
{
    return vector<T>::size();
}

template <typename T>
void mystl::stack<T>::push(T val)
{
    vector<T>::push_back(val);
}

template <typename T>
void mystl::stack<T>::pop()
{
    vector<T>::pop_back();
}

template <typename T>
void mystl::stack<T>::print() const
{
    vector<T>::print();
}

template <typename T>
mystl::stack<T>::~stack()
{

}

#endif // STACK_H