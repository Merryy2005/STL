#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <initializer_list>
#include <iterator>

namespace mystl
{
    template<typename T , std::size_t N>
    class Array
    {
        private:
            T arr[N];
        public:
            Array();
            Array(const std::initializer_list<T>&);
            Array(const Array&);
            Array(Array&&);
            Array& operator=(const Array&);
            Array& operator=(Array&&); 
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
            constexpr bool empty() const noexcept;
            constexpr std::size_t size() const noexcept;
            constexpr std::size_t max_size() const noexcept;
            void fill(const T&);
            void swap(Array&) noexcept;
            ~Array();

            template<typename U, std::size_t M>
            friend bool operator==(const Array<U , M>& , const Array<U , M>&);
            template<typename U, std::size_t M>
            friend bool operator!=(const Array<U , M>& , const Array<U , M>&);
            template<typename U, std::size_t M>
            friend bool operator<(const Array<U , M>& , const Array<U , M>&);
            template<typename U, std::size_t M>
            friend bool operator<=(const Array<U , M>& , const Array<U , M>&);
            template<typename U, std::size_t M>
            friend bool operator>(const Array<U , M>& , const Array<U , M>&);
            template<typename U, std::size_t M>
            friend bool operator>=(const Array<U , M>& , const Array<U , M>&);
    };
}

template<typename T , std::size_t N>
mystl::Array<T , N>::Array()
{
    for(std::size_t i = 0 ; i < N ; i++)
    {
        arr[i] = T();
    }
}

template<typename T , std::size_t N>
mystl::Array<T , N>::Array(const std::initializer_list<T>& initList)
{
    std::size_t i = 0;
    for (const T& value : initList) 
    {
        if (i >= N) break;
        arr[i++] = value;
    }
    while (i < N) 
    {
        arr[i++] = T();
    }
}

template<typename T , std::size_t N>
mystl::Array<T , N>::Array(const Array& other)
{
    for (std::size_t i = 0; i < N; i++) 
    {
        arr[i] = other.arr[i];
    }
}

template<typename T , std::size_t N>
mystl::Array<T , N>::Array(Array&& other)
{
    for (std::size_t i = 0; i < N; i++) 
    {
        arr[i] = std::move(other.arr[i]);
    }
}

template<typename T , std::size_t N>
mystl::Array<T , N>& mystl::Array<T , N>::operator=(const Array& other)
{
    if(this != &other)
    {
        for (std::size_t i = 0; i < N; i++) 
        {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

template<typename T , std::size_t N>
mystl::Array<T , N>& mystl::Array<T , N>::operator=(Array&& other)
{
    if(this != &other)
    {
        for (std::size_t i = 0; i < N; i++) 
        {
            arr[i] = std::move(other.arr[i]);
        }
    }
    return *this;
}

template<typename T , std::size_t N>
T& mystl::Array<T , N>::at(std::size_t pos)
{
    if(pos >= N)
    {
        throw std::out_of_range("out of range");
    }
    else
    {
        return arr[pos];
    }
}

template<typename T , std::size_t N>
const T& mystl::Array<T , N>::at(std::size_t pos) const
{
    if(pos >= N)
    {
        throw std::out_of_range("out of range");
    }
    else
    {
        return arr[pos];
    }
}

template<typename T , std::size_t N>
T& mystl::Array<T , N>::operator[](std::size_t pos)
{
    return arr[pos];
}

template<typename T , std::size_t N>
const T& mystl::Array<T , N>::operator[](std::size_t pos) const
{
    return arr[pos];
}

template<typename T , std::size_t N>
T& mystl::Array<T , N>::front()
{
    if (N == 0) 
    {
        throw std::out_of_range("Array is empty");
    }
    return arr[0];
}

template<typename T , std::size_t N>
const T& mystl::Array<T , N>::front() const
{
    if (N == 0) 
    {
        throw std::out_of_range("Array is empty");
    }
    return arr[0];
}

template<typename T , std::size_t N>
T& mystl::Array<T , N>::back()
{
    if (N == 0) 
    {
        throw std::out_of_range("Array is empty");
    }
    return arr[N-1];
}

template<typename T , std::size_t N>
const T& mystl::Array<T , N>::back() const
{
    if (N == 0) 
    {
        throw std::out_of_range("Array is empty");
    }
    return arr[N-1];
}

template<typename T , std::size_t N>
T* mystl::Array<T , N>::data() noexcept
{
    return arr;
}

template<typename T , std::size_t N>
const T* mystl::Array<T , N>::data() const noexcept
{
    return arr;
}

template<typename T , std::size_t N>
T* mystl::Array<T , N>::begin() noexcept
{
    return arr;
}

template<typename T , std::size_t N>
const T* mystl::Array<T , N>::begin() const noexcept
{
    return arr;
}

template<typename T , std::size_t N>
const T* mystl::Array<T , N>::cbegin() const noexcept
{
    return arr;
}

template<typename T , std::size_t N>
T* mystl::Array<T , N>::end() noexcept
{
    return arr + N;
}

template<typename T , std::size_t N>
const T* mystl::Array<T , N>::end() const noexcept
{
    return arr + N;
}

template<typename T , std::size_t N>
const T* mystl::Array<T , N>::cend() const noexcept
{
    return arr + N;
}

template<typename T , std::size_t N>
std::reverse_iterator<T*> mystl::Array<T , N>::rbegin() noexcept
{
    return std::reverse_iterator<T*>(end());
}

template<typename T , std::size_t N>
std::reverse_iterator<const T*> mystl::Array<T , N>::rbegin() const noexcept
{
    return std::reverse_iterator<const T*>(end());
}

template<typename T , std::size_t N>
std::reverse_iterator<const T*> mystl::Array<T , N>::crbegin() const noexcept
{
    return std::reverse_iterator<const T*>(end());
}            

template<typename T , std::size_t N>
std::reverse_iterator<T*> mystl::Array<T , N>::rend() noexcept
{
    return std::reverse_iterator<T*>(begin());
}

template<typename T , std::size_t N>
std::reverse_iterator<const T*> mystl::Array<T , N>::rend() const noexcept
{
    return std::reverse_iterator<const T*>(begin());
}

template<typename T , std::size_t N>
std::reverse_iterator<const T*> mystl::Array<T , N>::crend() const noexcept
{
    return std::reverse_iterator<const T*>(begin());
}

template<typename T , std::size_t N>
constexpr bool mystl::Array<T , N>::empty() const noexcept
{
    return N == 0;
}

template<typename T , std::size_t N>
constexpr std::size_t mystl::Array<T , N>::size() const noexcept
{
    return N;
}
            
template<typename T , std::size_t N>
constexpr std::size_t mystl::Array<T , N>::max_size() const noexcept
{
    return N;
}

template<typename T , std::size_t N>
void mystl::Array<T , N>::fill(const T& value)
{
    for(std::size_t i = 0 ; i < N ; i++)
    {
        arr[i] = value;
    }
    return;
}

template<typename T , std::size_t N>
void mystl::Array<T , N>::swap(Array& other) noexcept
{
    for(std::size_t i = 0 ; i < N ; i++)
    {
        std::swap(arr[i] , other.arr[i]);
    }
    return;
}

template<typename T , std::size_t N>
mystl::Array<T , N>::~Array(){}

namespace mystl
{
    template<typename U , std::size_t M>
    bool operator==(const mystl::Array<U , M>& lhs, const mystl::Array<U , M>& rhs)
    {
        for(std::size_t i = 0 ; i < M ; i++)
        {
            if(lhs.arr[i] != rhs.arr[i])
            {
                return false;
            }
        }
        return true;
    }

    template<typename U , std::size_t M>
    bool operator!=(const mystl::Array<U , M>& lhs, const mystl::Array<U , M>& rhs)
    {
        return !(lhs == rhs);
    }

    template<typename U , std::size_t M>
    bool operator<(const mystl::Array<U , M>& lhs, const mystl::Array<U , M>& rhs)
    {
        for (std::size_t i = 0; i < M; ++i)
        {
            if (lhs.arr[i] < rhs.arr[i])
            {
                return true;
            }
            if (lhs.arr[i] > rhs.arr[i])
            {
                return false;
            }
        }
        return false; 
    }

    template<typename U , std::size_t M>
    bool operator<=(const mystl::Array<U , M>& lhs, const mystl::Array<U , M>& rhs)
    {
        return !(lhs > rhs);
    }

    template<typename U , std::size_t M>
    bool operator>(const mystl::Array<U , M>& lhs, const mystl::Array<U , M>& rhs)
    {
        return rhs < lhs;
    }

    template<typename U , std::size_t M>
    bool operator>=(const mystl::Array<U , M>& lhs, const mystl::Array<U , M>& rhs)
    {
        return !(lhs < rhs);
    }
}

#endif//ARRAY_H