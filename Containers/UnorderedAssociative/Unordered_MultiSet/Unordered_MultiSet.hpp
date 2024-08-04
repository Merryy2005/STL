#ifndef UNORDERED_MULTISET_H
#define UNORDERED_MULTISET_H

#include "C:\STL\Containers\UnorderedAssociative\HashTable.hpp"

namespace mystl
{
    template<typename Key>
    class Unordered_MultiSet : public HashMap<Key, Key>
    {
        public:
            Unordered_MultiSet();
            ~Unordered_MultiSet();
            Unordered_MultiSet(const Unordered_MultiSet& other);
            Unordered_MultiSet(Unordered_MultiSet&& other) noexcept;
            Unordered_MultiSet& operator=(const Unordered_MultiSet& other);
            Unordered_MultiSet& operator=(Unordered_MultiSet&& other) noexcept;
            void insert(const Key& k);
            void emplace(Key&& k);
            bool contains(const Key& k) const;
            std::size_t count(const Key& k) const;
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
mystl::Unordered_MultiSet<Key>::Unordered_MultiSet() : HashMap<Key, Key>(Container::MultiSet) {}

template<typename Key>
mystl::Unordered_MultiSet<Key>::~Unordered_MultiSet() {}

template<typename Key>
mystl::Unordered_MultiSet<Key>::Unordered_MultiSet(const Unordered_MultiSet& other) : HashMap<Key, Key>(Container::MultiSet)
{
    *this = other;
}

template<typename Key>
mystl::Unordered_MultiSet<Key>::Unordered_MultiSet(Unordered_MultiSet&& other) noexcept : HashMap<Key, Key>(Container::MultiSet)
{
    *this = std::move(other);
}

template<typename Key>
mystl::Unordered_MultiSet<Key>& mystl::Unordered_MultiSet<Key>::operator=(const mystl::Unordered_MultiSet<Key>& other)
{
    if(this != &other)
    {
        HashMap<Key, Key>::operator=(other);
    }
    return *this;
}

template<typename Key>
mystl::Unordered_MultiSet<Key>& mystl::Unordered_MultiSet<Key>::operator=(Unordered_MultiSet&& other) noexcept
{
    if (this != &other)
    {
        HashMap<Key, Key>::operator=(std::move(other));
    }
    return *this;
}

template<typename Key>
void mystl::Unordered_MultiSet<Key>::insert(const Key& k)
{
    HashMap<Key, Key>::insert(k, k);
}

template<typename Key>
void mystl::Unordered_MultiSet<Key>::emplace(Key&& k)
{
    insert(std::move(k));
}

template<typename Key>
bool mystl::Unordered_MultiSet<Key>::contains(const Key& k) const
{
    return HashMap<Key, Key>::find(k) > 0;
}

template<typename Key>
std::size_t mystl::Unordered_MultiSet<Key>::count(const Key& k) const
{
    return HashMap<Key, Key>::find(k);
}

template<typename Key>
bool mystl::Unordered_MultiSet<Key>::empty() const
{
    return HashMap<Key, Key>::count == 0;
}

template<typename Key>
std::size_t mystl::Unordered_MultiSet<Key>::size() const
{
    return HashMap<Key, Key>::count;
}

template<typename Key>
void mystl::Unordered_MultiSet<Key>::erase(const Key& k)
{
    HashMap<Key, Key>::remove(k);
}

template<typename Key>
void mystl::Unordered_MultiSet<Key>::print() const
{
    HashMap<Key, Key>::print();
}

template<typename Key>
const Key* mystl::Unordered_MultiSet<Key>::begin() const
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
const Key* mystl::Unordered_MultiSet<Key>::end() const
{
    return nullptr;
}

template<typename Key>
void mystl::Unordered_MultiSet<Key>::clear()
{
    HashMap<Key, Key>::clear();
}


#endif //UNORDERED_MULTISET_H
