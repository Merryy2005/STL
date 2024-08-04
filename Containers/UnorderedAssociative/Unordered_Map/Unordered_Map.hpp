#ifndef UNORDERED_MAP_H
#define UNORDERED_MAP_H

#include "C:\STL\Containers\UnorderedAssociative\HashTable.hpp"

namespace mystl
{
    template<typename Key , typename Value>
    class Unordered_Map : public HashMap<Key, Value>
    {
        public:
            Unordered_Map();
            ~Unordered_Map();
            Unordered_Map(const Unordered_Map& other);
            Unordered_Map(Unordered_Map&& other) noexcept;
            Unordered_Map& operator=(const Unordered_Map& other);
            Unordered_Map& operator=(Unordered_Map&& other) noexcept;
            Value& operator[](const Key& k);
            const Value& operator[](const Key& k) const;
            Value& at(const Key& k);
            const Value& at(const Key& k) const;
            void insert(const Key& k, const Value& v);
            void emplace(Key&& k, Value&& v);
            bool contains(const Key& k) const;
            void erase(const Key& k);
            void print() const;
            Node<Key, Value>* begin() const;
            Node<Key, Value>* end() const;
            bool empty() const;
            std::size_t size() const;
            void clear();
    };
}

template<typename Key , typename Value>
mystl::Unordered_Map<Key , Value>::Unordered_Map() : HashMap<Key, Value>(Container::Map) {}

template<typename Key , typename Value>
mystl::Unordered_Map<Key , Value>::~Unordered_Map() {}

template<typename Key , typename Value>
mystl::Unordered_Map<Key , Value>::Unordered_Map(const Unordered_Map& other) : HashMap<Key, Value>(Container::Map)
{
    *this = other;
}

template<typename Key , typename Value>
mystl::Unordered_Map<Key , Value>::Unordered_Map(Unordered_Map&& other) noexcept : HashMap<Key, Value>(Container::Map)
{
    *this = std::move(other);
}

template<typename Key , typename Value>
mystl::Unordered_Map<Key , Value>& mystl::Unordered_Map<Key , Value>::operator=(const mystl::Unordered_Map<Key , Value>& other)
{
    if(this != &other)
    {
        HashMap<Key, Value>::operator=(other);
    }
    return *this;
}

template<typename Key , typename Value>
mystl::Unordered_Map<Key , Value>& mystl::Unordered_Map<Key , Value>::operator=(Unordered_Map&& other) noexcept
{
    if (this != &other)
    {
        HashMap<Key, Value>::operator=(std::move(other));
    }
    return *this;
}

template<typename Key, typename Value>
Value& mystl::Unordered_Map<Key, Value>::operator[](const Key& k) 
{
    std::size_t index = HashMap<Key, Value>::hashFunction(k);
    auto& list = HashMap<Key, Value>::vec[index];
    for (auto it = list.begin(); it != list.end(); it = it->next)
    {
        if (it->val.key == k)
        {
            return it->val.value[0];
        }
    }
    list.push_front(Node<Key, Value>(k, Value(), Container::Map));
    ++(HashMap<Key, Value>::count);
    if (HashMap<Key, Value>::count > HashMap<Key, Value>::cap * 0.75)
    {
        HashMap<Key, Value>::resize();
    }
    return list.begin()->val.value[0];
}

template<typename Key, typename Value>
const Value& mystl::Unordered_Map<Key, Value>::operator[](const Key& k) const
{
    std::size_t index = HashMap<Key, Value>::hashFunction(k);
    auto& list = HashMap<Key, Value>::vec[index];
    for (auto it = list.begin(); it != list.end(); it = it->next)
    {
        if (it->val.key == k)
        {
            return it->val.value[0];
        }
    }
    return Value();
}

template<typename Key, typename Value>
Value& mystl::Unordered_Map<Key, Value>::at(const Key& k) 
{
    std::size_t index = HashMap<Key, Value>::hashFunction(k);
    auto& list = HashMap<Key, Value>::vec[index];
    for (auto it = list.begin(); it != list.end(); it = it->next)
    {
        if (it->val.key == k)
        {
            return it->val.value[0];
        }
    }
    throw std::out_of_range("Key not found");
}

template<typename Key, typename Value>
const Value& mystl::Unordered_Map<Key, Value>::at(const Key& k) const 
{
    std::size_t index = HashMap<Key, Value>::hashFunction(k);
    auto& list = HashMap<Key, Value>::vec[index];
    for (auto it = list.begin(); it != list.end(); it = it->next)
    {
        if (it->val.key == k)
        {
            return it->val.value[0];
        }
    }
    throw std::out_of_range("Key not found");
}

template<typename Key , typename Value>
void mystl::Unordered_Map<Key , Value>::insert(const Key& k , const Value& v)
{
    HashMap<Key, Value>::insert(k, v);
}

template<typename Key , typename Value>
void mystl::Unordered_Map<Key , Value>::emplace(Key&& k , Value&& v)
{
    insert(std::move(k) , std::move(v));
}

template<typename Key , typename Value>
bool mystl::Unordered_Map<Key , Value>::contains(const Key& k) const
{
    return HashMap<Key, Value>::find(k) > 0;
}

template<typename Key , typename Value>
void mystl::Unordered_Map<Key , Value>::erase(const Key& k)
{
    HashMap<Key, Value>::remove(k);
}

template<typename Key , typename Value>
void mystl::Unordered_Map<Key , Value>::print() const
{
    HashMap<Key, Value>::print();
}

template<typename Key, typename Value>
mystl::Node<Key, Value>* mystl::Unordered_Map<Key, Value>::begin() const
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
mystl::Node<Key, Value>* mystl::Unordered_Map<Key , Value>::end() const
{
    return nullptr;
}

template<typename Key , typename Value>
bool mystl::Unordered_Map<Key , Value>::empty() const
{
    return HashMap<Key, Value>::count == 0;
}

template<typename Key , typename Value>
std::size_t mystl::Unordered_Map<Key , Value>::size() const
{
    return HashMap<Key, Value>::count;
}

template<typename Key , typename Value>
void mystl::Unordered_Map<Key , Value>::clear()
{
    HashMap<Key, Value>::clear();
}


#endif //UNORDERED_MAP_H
