#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <initializer_list>
#include <limits>

namespace mystl
{
    template<typename T>
    class Vector
    {
        protected:
            std::size_t m_size;
            std::size_t m_cap;
            T* m_arr;
            void reallocate(std::size_t);
        public:
            Vector();
            explicit Vector(std::size_t);
            template <typename InputIterator>
            Vector(InputIterator, InputIterator);
            Vector(const std::initializer_list<T>&);
            Vector(const Vector&);
            Vector(Vector&&);
            Vector& operator=(const Vector&);
            Vector& operator=(Vector&&);
            void assign(std::size_t, const T&);
            template <typename InputIterator>
            void assign(InputIterator, InputIterator);
            void assign(std::initializer_list<T>&);
            T& at(std::size_t);
            const T& at(std::size_t) const;
            T& operator[](std::size_t);
            const T& operator[](std::size_t) const;
            T& front();
            const T& front() const;
            T& back();
            const T& back() const;
            T* data() noexcept;
            const T* data() const noexcept;
            T* begin() noexcept;
            const T* begin() const noexcept;
            const T* cbegin() const noexcept;
            T* end() noexcept;
            const T* end() const noexcept;
            const T* cend() const noexcept;
            std::reverse_iterator<T*> rbegin() noexcept;
            std::reverse_iterator<const T*> rbegin() const noexcept;
            std::reverse_iterator<const T*> crbegin() const noexcept;
            std::reverse_iterator<T*> rend() noexcept;
            std::reverse_iterator<const T*> rend() const noexcept;
            std::reverse_iterator<const T*> crend() const noexcept;
            bool empty() const;
            std::size_t size() const;
            std::size_t max_size() const;
            void reserve(std::size_t);
            std::size_t capacity() const;
            void clear();
            void insert(std::size_t pos, const T&);
            void erase(std::size_t pos);
            void push_back(const T&);
            void pop_back();
            void push_front(const T&);
            void pop_front();
            void resize(std::size_t);
            void swap(Vector&);
            ~Vector();

            template<typename U>
            friend bool operator==(const Vector<U>& , const Vector<U>&);
            template<typename U>
            friend bool operator!=(const Vector<U>& , const Vector<U>&);
            template<typename U>
            friend bool operator<(const Vector<U>& , const Vector<U>&);
            template<typename U>
            friend bool operator<=(const Vector<U>& , const Vector<U>&);
            template<typename U>
            friend bool operator>(const Vector<U>& , const Vector<U>&);
            template<typename U>
            friend bool operator>=(const Vector<U>& , const Vector<U>&);
    };
}

template <typename T>
mystl::Vector<T>::Vector() : m_size(0) , m_cap(1) , m_arr(new T[m_cap])
{

}

template <typename T>
mystl::Vector<T>::Vector(std::size_t count) : m_size(count), m_cap(count > 0 ? 2 * count : 1), m_arr(new T[m_cap])
{
    for(std::size_t i = 0 ; i < m_size ; i++)
    {
        m_arr[i] = T();
    }
}

template<typename T>
template <typename InputIterator>
mystl::Vector<T>::Vector(InputIterator first, InputIterator last)
{
    std::size_t count = last - first;
    m_size = count;
    m_cap = count > 0 ? 2 * count : 1;
    m_arr = new T[m_cap];
    InputIterator it = first;
    for (std::size_t i = 0; i < m_size; ++i) 
    {
        m_arr[i] = *it;
        ++it;
    }
}

template <typename T>
mystl::Vector<T>::Vector(const std::initializer_list<T>& initList) : m_size(initList.size()) , m_cap(m_size > 0 ? 2 * m_size : 1) , m_arr(new T[m_cap]) 
{
    std::size_t i = 0;
    for (auto it = initList.begin(); it != initList.end(); ++it) 
    {
        m_arr[i++] = *it;
    }
}

template <typename T>
mystl::Vector<T>::Vector(const Vector<T>& other) : m_size(other.m_size) , m_cap(other.m_cap) , m_arr(new T[m_cap])
{
    for(std::size_t i = 0 ; i < m_size ; i++)
    {
        m_arr[i] = other.m_arr[i];
    }
}

template <typename T>
mystl::Vector<T>::Vector(Vector<T>&& other) : m_size(other.m_size) , m_cap(other.m_cap) , m_arr(other.m_arr)
{
    other.m_size = 0;
    other.m_cap = 0;
    other.m_arr = nullptr;
}

template <typename T>
mystl::Vector<T>& mystl::Vector<T>::operator=(const mystl::Vector<T>& other)
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
mystl::Vector<T>& mystl::Vector<T>::operator=(mystl::Vector<T>&& other)
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
void mystl::Vector<T>::reallocate(std::size_t new_cap)
{
    T* tmp = new T[new_cap];
    for (std::size_t i = 0; i < m_size; ++i) 
    {
        tmp[i] = std::move(m_arr[i]);
    }
    delete[] m_arr;
    m_arr = tmp;
    m_cap = new_cap;
}

template <typename T>
void mystl::Vector<T>::assign(std::size_t count, const T& val)
{
    if (count > m_cap) 
    {
        reallocate(count);
    }
    m_size = count;
    for (std::size_t i = 0; i < count; i++) 
    {
        m_arr[i] = val;
    }
}

template <typename T>    
template <typename InputIterator>
void mystl::Vector<T>::assign(InputIterator first, InputIterator last)
{
    std::size_t count = last - first;
    if (count > m_cap) 
    {
        reallocate(count);
    }
    m_size = count;
    InputIterator it = first;
    for (std::size_t i = 0; i < m_size; ++i) 
    {
        m_arr[i] = *it;
        ++it;
    }
}

template <typename T>  
void  mystl::Vector<T>::assign(std::initializer_list<T>& initList)
{
    if (initList.size() > m_cap) 
    {
        reallocate(initList.size());
    }
    m_size = initList.size();
    std::size_t i = 0;
    for (const T& val : initList)
    {
        m_arr[i++] = val;
    }
}

template<typename T>
T& mystl::Vector<T>::at(std::size_t pos)
{
    if(pos >= m_size)
    {
        throw std::out_of_range("out of range");
    }
    else
    {
        return m_arr[pos];
    }
}

template<typename T>
const T& mystl::Vector<T>::at(std::size_t pos) const
{
    if(pos >= m_size)
    {
        throw std::out_of_range("out of range");
    }
    else
    {
        return m_arr[pos];
    }
}

template<typename T>
T& mystl::Vector<T>::operator[](std::size_t pos)
{
    return m_arr[pos];
}

template<typename T>
const T& mystl::Vector<T>::operator[](std::size_t pos) const
{
    return m_arr[pos];
}

template<typename T>
T& mystl::Vector<T>::front()
{
    if (m_size == 0) 
    {
        throw std::out_of_range("Vector is empty");
    }
    return m_arr[0];
}

template<typename T>
const T& mystl::Vector<T>::front() const
{
    if (m_size == 0) 
    {
        throw std::out_of_range("Vector is empty");
    }
    return m_arr[0];
}

template<typename T>
T& mystl::Vector<T>::back()
{
    if (m_size == 0) 
    {
        throw std::out_of_range("Vector is empty");
    }
    return m_arr[m_size-1];
}

template<typename T>
const T& mystl::Vector<T>::back() const
{
    if (m_size == 0) 
    {
        throw std::out_of_range("Vector is empty");
    }
    return m_arr[m_size-1];
}

template<typename T>
T* mystl::Vector<T>::data() noexcept
{
    return m_arr;
}

template<typename T>
const T* mystl::Vector<T>::data() const noexcept
{
    return m_arr;
}

template<typename T>
T* mystl::Vector<T>::begin() noexcept
{
    return m_arr;
}

template<typename T>
const T* mystl::Vector<T>::begin() const noexcept
{
    return m_arr;
}

template<typename T>
const T* mystl::Vector<T>::cbegin() const noexcept
{
    return m_arr;
}

template<typename T>
T* mystl::Vector<T>::end() noexcept
{
    return m_arr + m_size;
}

template<typename T>
const T* mystl::Vector<T>::end() const noexcept
{
    return m_arr + m_size;
}

template<typename T>
const T* mystl::Vector<T>::cend() const noexcept
{
    return m_arr + m_size;
}

template<typename T>
std::reverse_iterator<T*> mystl::Vector<T>::rbegin() noexcept
{
    return std::reverse_iterator<T*>(end());
}

template<typename T>
std::reverse_iterator<const T*> mystl::Vector<T>::rbegin() const noexcept
{
    return std::reverse_iterator<const T*>(end());
}

template<typename T>
std::reverse_iterator<const T*> mystl::Vector<T>::crbegin() const noexcept
{
    return std::reverse_iterator<const T*>(end());
}            

template<typename T>
std::reverse_iterator<T*> mystl::Vector<T>::rend() noexcept
{
    return std::reverse_iterator<T*>(begin());
}

template<typename T>
std::reverse_iterator<const T*> mystl::Vector<T>::rend() const noexcept
{
    return std::reverse_iterator<const T*>(begin());
}

template<typename T>
std::reverse_iterator<const T*> mystl::Vector<T>::crend() const noexcept
{
    return std::reverse_iterator<const T*>(begin());
}

template <typename T>
bool mystl::Vector<T>::empty() const
{
    return m_size == 0;
}

template <typename T>
std::size_t mystl::Vector<T>::size() const
{
    return m_size;
}

template <typename T>
std::size_t mystl::Vector<T>::max_size() const
{
    return std::numeric_limits<std::size_t>::max() / sizeof(T);
}

template <typename T>
void mystl::Vector<T>::reserve(std::size_t new_cap)
{
    if(m_cap < new_cap)
    {
        m_cap = new_cap;
        T* temp = static_cast<T*>(operator new(m_cap * sizeof(T)));
        if(temp == nullptr)
        {
            std::cout << "Can't do reserve" << std::endl;
            return;
        }
        for(std::size_t i = 0 ; i < m_size; i++)
        {
            temp[i] = std::move(m_arr[i]);
        }
        delete[] m_arr;
        m_arr = temp;  
    }
    return;
}

template <typename T>
std::size_t mystl::Vector<T>::capacity() const
{
    return m_cap;
}

template<typename T>
void mystl::Vector<T>::clear()
{
    for (std::size_t i = 0; i < m_size; i++) 
    {
        m_arr[i].~T();
    }
    m_size = 0;
    return;
}

template <typename T>
void mystl::Vector<T>::insert(std::size_t pos , const T& val)
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
    for(std::size_t i = m_size ; i > pos ; i--)
    {
        m_arr[i] = m_arr[i-1];
    }
    m_arr[pos] = val;
    m_size++;
    return;
}

template <typename T>
void mystl::Vector<T>::erase(std::size_t pos)
{
    if (pos >= m_size) {
        std::cout << "Wrong position" << std::endl;
        return;
    }
    m_arr[pos].~T();
    for (std::size_t i = pos; i < m_size - 1; i++) 
    {
        m_arr[i] = m_arr[i+1];
    }
    --m_size;
}

template <typename T>
void mystl::Vector<T>::push_back(const T& val)
{
    if(m_size == m_cap)
    {
        T* temp = new T[m_cap*2];
        for(std::size_t i = 0 ; i < m_size; i++)
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
void mystl::Vector<T>::pop_back()
{
    if(m_size == 0)
    {
        throw std::out_of_range("Empty vector, can't call pop_back()");
    }
    else
    {
        m_arr[--m_size].~T();
    }
}

template <typename T>
void mystl::Vector<T>::push_front(const T& val)
{
    if(m_size == m_cap)
    {
        T* temp = new T[m_cap*2];
        for(std::size_t i = 0 ; i < m_size; i++)
        {
            temp[i+1] = m_arr[i];
        }
        delete[] m_arr;
        m_arr = temp;
        m_cap *= 2;
    }
    else
    {
        for(std::size_t i = m_size ; i > 0 ; i--)
        {
            m_arr[i] = m_arr[i-1];
        }
    }
    m_arr[0] = val;
    m_size++;
}

template <typename T>
void mystl::Vector<T>::pop_front()
{
    if(m_size == 0)
    {
        throw std::out_of_range("Empty vector, can't call pop_front()");
    }
    else
    {
        m_arr[0].~T();
        for(std::size_t i = 0 ; i < (m_size-1) ; i++)
        {
            m_arr[i] = m_arr[i+1];
        }
        m_arr[--m_size].~T();
    }
}

template <typename T>
void mystl::Vector<T>::resize(std::size_t count)
{
    if(m_size >= count)
    {
        for (std::size_t i = count; i < m_size; i++) 
        {
            m_arr[i].~T();
        }
        m_size = count;
    }
    else
    {
        if(m_cap < count)
        {
            m_cap = 2*count;
            T* temp = new T[m_cap];
            for(std::size_t i = 0 ; i < m_size; i++)
            {
                temp[i] = m_arr[i];
            }
            delete[] m_arr;
            m_arr = temp;
        }
        m_size = count;
    }
    return;
}

template <typename T>
void mystl::Vector<T>::swap(Vector& other)
{
    std::swap(m_arr, other.m_arr);  
    std::swap(m_size, other.m_size); 
    std::swap(m_cap, other.m_cap);
    return;
}

template <typename T>
mystl::Vector<T>::~Vector()
{
    delete[] m_arr;
}

namespace mystl
{
    template<typename U>
    bool operator==(const mystl::Vector<U>& lhs, const mystl::Vector<U>& rhs)
    {
        if(lhs.size() != rhs.size())
        {
            return false;
        }
        for(std::size_t i = 0 ; i < lhs.size() ; i++)
        {
            if(lhs.m_arr[i] != rhs.m_arr[i])
            {
                return false;
            }
        }
        return true;
    }

    template<typename U>
    bool operator!=(const mystl::Vector<U>& lhs, const mystl::Vector<U>& rhs)
    {
        return !(lhs == rhs);
    }

    template<typename U>
    bool operator<(const mystl::Vector<U>& lhs, const mystl::Vector<U>& rhs)
    {
        for (std::size_t i = 0; i < std::min(lhs.size(), rhs.size()); ++i) 
        {
            if (lhs.m_arr[i] < rhs.m_arr[i]) 
            {
                return true;
            }
            if (lhs.m_arr[i] > rhs.m_arr[i]) 
            {
                return false; 
            }
        }
        return lhs.size() < rhs.size();
    }

    template<typename U>
    bool operator<=(const mystl::Vector<U>& lhs, const mystl::Vector<U>& rhs)
    {
        return !(lhs > rhs);
    }

    template<typename U>
    bool operator>(const mystl::Vector<U>& lhs, const mystl::Vector<U>& rhs)
    {
        return rhs < lhs;
    }

    template<typename U>
    bool operator>=(const mystl::Vector<U>& lhs, const mystl::Vector<U>& rhs)
    {
        return !(lhs < rhs);
    }
}

#endif //VECTOR_H
