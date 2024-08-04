#ifndef UNORDERED_MULTIMAP_H
#define UNORDERED_MULTIMAP_H

#include "C:\STL\Containers\UnorderedAssociative\HashTable.hpp"

namespace mystl
{
    template<typename Key , typename Value>
    class Unordered_MultiMap : public HashMap<Key, Value>
    {
        public:
            Unordered_MultiMap();
            ~Unordered_MultiMap();
            Unordered_MultiMap(const Unordered_MultiMap& other);
            Unordered_MultiMap(Unordered_MultiMap&& other) noexcept;
            Unordered_MultiMap& operator=(const Unordered_MultiMap& other);
            Unordered_MultiMap& operator=(Unordered_MultiMap&& other) noexcept;
            void insert(const Key& k, const Value& v);
            void emplace(Key&& k, Value&& v);
            bool contains(const Key& k) const;
            std::size_t count(const Key& k) const;
            void erase(const Key& k);
            void print() const;
            const Node<Key, Value>* begin() const;
            const Node<Key, Value>* end() const;
            bool empty() const;
            std::size_t size() const;
            void clear();
    };
}

template<typename Key , typename Value>
mystl::Unordered_MultiMap<Key , Value>::Unordered_MultiMap() : HashMap<Key, Value>(Container::MultiMap) {}

template<typename Key , typename Value>
mystl::Unordered_MultiMap<Key , Value>::~Unordered_MultiMap() {}

template<typename Key , typename Value>
mystl::Unordered_MultiMap<Key , Value>::Unordered_MultiMap(const Unordered_MultiMap& other) : HashMap<Key, Value>(Container::MultiMap)
{
    *this = other;
}

template<typename Key , typename Value>
mystl::Unordered_MultiMap<Key , Value>::Unordered_MultiMap(Unordered_MultiMap&& other) noexcept : HashMap<Key, Value>(Container::MultiMap)
{
    *this = std::move(other);
}

template<typename Key , typename Value>
mystl::Unordered_MultiMap<Key , Value>& mystl::Unordered_MultiMap<Key , Value>::operator=(const mystl::Unordered_MultiMap<Key , Value>& other)
{
    if(this != &other)
    {
        HashMap<Key, Value>::operator=(other);
    }
    return *this;
}

template<typename Key , typename Value>
mystl::Unordered_MultiMap<Key , Value>& mystl::Unordered_MultiMap<Key , Value>::operator=(Unordered_MultiMap&& other) noexcept
{
    if (this != &other)
    {
        HashMap<Key, Value>::operator=(std::move(other));
    }
    return *this;
}

template<typename Key , typename Value>
void mystl::Unordered_MultiMap<Key , Value>::insert(const Key& k , const Value& v)
{
    HashMap<Key, Value>::insert(k, v);
}

template<typename Key , typename Value>
void mystl::Unordered_MultiMap<Key , Value>::emplace(Key&& k , Value&& v)
{
    insert(std::move(k) , std::move(v));
}

template<typename Key , typename Value>
bool mystl::Unordered_MultiMap<Key , Value>::contains(const Key& k) const
{
    return HashMap<Key, Value>::find(k) > 0;
}

template<typename Key , typename Value>
std::size_t mystl::Unordered_MultiMap<Key , Value>::count(const Key& k) const
{
    return HashMap<Key, Value>::find(k);
}

template<typename Key , typename Value>
void mystl::Unordered_MultiMap<Key , Value>::erase(const Key& k)
{
    HashMap<Key, Value>::remove(k);
}

template<typename Key , typename Value>
void mystl::Unordered_MultiMap<Key , Value>::print() const
{
    HashMap<Key, Value>::print();
}

template<typename Key, typename Value>
const mystl::Node<Key, Value>* mystl::Unordered_MultiMap<Key, Value>::begin() const
{
    for (std::size_t i = 0; i < HashMap<Key, Value>::cap; ++i)
    {
        if (!HashMap<Key, Value>::vec[i].empty())
        {
            return &(HashMap<Key, Value>::vec[i].front());
        }
    }
    return nullptr;
}

template<typename Key , typename Value>
const mystl::Node<Key, Value>* mystl::Unordered_MultiMap<Key , Value>::end() const
{
    return nullptr;
}

template<typename Key , typename Value>
bool mystl::Unordered_MultiMap<Key , Value>::empty() const
{
    return HashMap<Key, Value>::count == 0;
}

template<typename Key , typename Value>
std::size_t mystl::Unordered_MultiMap<Key , Value>::size() const
{
    return HashMap<Key, Value>::count;
}

template<typename Key , typename Value>
void mystl::Unordered_MultiMap<Key , Value>::clear()
{
    HashMap<Key, Value>::clear();
}


#endif //UNORDERED_MULTIMAP_H
