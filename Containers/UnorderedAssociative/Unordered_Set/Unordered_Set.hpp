#ifndef UNORDERED_SET_H
#define UNORDERED_SET_H

#include "C:\STL\Containers\UnorderedAssociative\HashTable.hpp"

namespace mystl
{
    template<typename Key>
    class Unordered_Set : public HashMap<Key, Key>
    {
        public:
            Unordered_Set();
            ~Unordered_Set();
            Unordered_Set(const Unordered_Set& other);
            Unordered_Set(Unordered_Set&& other) noexcept;
            Unordered_Set& operator=(const Unordered_Set& other);
            Unordered_Set& operator=(Unordered_Set&& other) noexcept;
            void insert(const Key& k);
            void emplace(Key&& k);
            bool contains(const Key& k) const;
            bool empty() const;
            std::size_t size() const;
            void erase(const Key& k);
            void print() const;
            const Key* begin() const;
            const Key* end() const;
            void clear();
    };
}

template<typename Key>
mystl::Unordered_Set<Key>::Unordered_Set() : HashMap<Key, Key>(Container::Set) {}

template<typename Key>
mystl::Unordered_Set<Key>::~Unordered_Set() {}

template<typename Key>
mystl::Unordered_Set<Key>::Unordered_Set(const Unordered_Set& other) : HashMap<Key, Key>(Container::Set)
{
    *this = other;
}

template<typename Key>
mystl::Unordered_Set<Key>::Unordered_Set(Unordered_Set&& other) noexcept : HashMap<Key, Key>(Container::Set)
{
    *this = std::move(other);
}

template<typename Key>
mystl::Unordered_Set<Key>& mystl::Unordered_Set<Key>::operator=(const mystl::Unordered_Set<Key>& other)
{
    if(this != &other)
    {
        HashMap<Key, Key>::operator=(other);
    }
    return *this;
}

template<typename Key>
mystl::Unordered_Set<Key>& mystl::Unordered_Set<Key>::operator=(Unordered_Set&& other) noexcept
{
    if (this != &other)
    {
        HashMap<Key, Key>::operator=(std::move(other));
    }
    return *this;
}

template<typename Key>
void mystl::Unordered_Set<Key>::insert(const Key& k)
{
    HashMap<Key, Key>::insert(k, k);
}

template<typename Key>
void mystl::Unordered_Set<Key>::emplace(Key&& k)
{
    insert(std::move(k));
}

template<typename Key>
bool mystl::Unordered_Set<Key>::contains(const Key& k) const
{
    return HashMap<Key, Key>::find(k) > 0;
}

template<typename Key>
bool mystl::Unordered_Set<Key>::empty() const
{
    return HashMap<Key, Key>::count == 0;
}

template<typename Key>
std::size_t mystl::Unordered_Set<Key>::size() const
{
    return HashMap<Key, Key>::count;
}

template<typename Key>
void mystl::Unordered_Set<Key>::erase(const Key& k)
{
    HashMap<Key, Key>::remove(k);
}

template<typename Key>
void mystl::Unordered_Set<Key>::print() const
{
    HashMap<Key, Key>::print();
}

template<typename Key>
const Key* mystl::Unordered_Set<Key>::begin() const
{
    for (std::size_t i = 0; i < HashMap<Key, Key>::cap; ++i)
    {
        if (!HashMap<Key, Key>::vec[i].empty())
        {
            return &(HashMap<Key, Key>::vec[i].front().key);
        }
    }
    return nullptr;
}

template<typename Key>
const Key* mystl::Unordered_Set<Key>::end() const
{
    return nullptr;
}

template<typename Key>
void mystl::Unordered_Set<Key>::clear()
{
    HashMap<Key, Key>::clear();
}


#endif //UNORDERED_SET_H
