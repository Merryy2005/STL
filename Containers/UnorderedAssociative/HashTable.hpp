#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include <functional>
#include "C:\STL\Containers\Sequence\Vector\Vector.hpp"
#include "C:\STL\Containers\Sequence\ForwardList\ForwardList.hpp"

namespace mystl
{
    enum class Container 
    {
        Map,
        MultiMap,
        Set,
        MultiSet
    };

    template<typename Key, typename Value>
    class HashMap;

    template<typename Key, typename Value>
    class Node
    {
        public:
            Key key;
            mystl::Vector<Value> value;
        Container cType;
            Node(const Key&, const Value&, Container);
            Node& operator*() { return *this; }
            const Node& operator*() const { return *this; }
            Node* operator->() { return this; }
            const Node* operator->() const { return this; }
        friend class HashMap<Key, Value>;
    };

    template<typename Key, typename Value>
    class HashMap
    {
        protected:
            std::size_t count;
            std::size_t cap;
            Vector<ForwardList<Node<Key, Value>>> vec;
            Container containerType;
            std::size_t hashFunction(const Key&) const;
            bool isPrime(int) const;
            int nextPrime(int) const;
            void resize();
        public:
            HashMap(Container);
            HashMap(const HashMap& other);
            HashMap(HashMap&& other) noexcept;
            HashMap& operator=(const HashMap& other);
            HashMap& operator=(HashMap&& other) noexcept;
            void insert(const Key&, const Value&);
            void remove(const Key&);
            std::size_t find(const Key&) const;
            void print() const;
            void clear();
            ~HashMap();
    };
}

template<typename Key, typename Value>
mystl::Node<Key, Value>::Node(const Key& k, const Value& v, mystl::Container c)
    : key(k), value({v}), cType(c)
{
}

template<typename Key, typename Value>
mystl::HashMap<Key, Value>::HashMap(mystl::Container c)
    : count(0), cap(31), vec(31), containerType(c)
{
}

template<typename Key, typename Value>
mystl::HashMap<Key, Value>::HashMap(const HashMap& other)
    : count(other.count), cap(other.cap), containerType(other.containerType), vec(other.cap)
{
    for (std::size_t i = 0; i < other.vec.size(); ++i)
    {
        for (const auto& node : other.vec[i])
        {
            vec[i].push_front(Node<Key, Value>(node.val.key, node.val.value[0], node.val.cType));
            if (containerType == Container::MultiMap || containerType == Container::MultiSet)
            {
                for (std::size_t j = 1; j < node.val.value.size(); ++j)
                {
                    vec[i].back().value.push_back(node.val.value[j]);
                }
            }
        }
    }
}

template<typename Key, typename Value>
mystl::HashMap<Key, Value>::HashMap(HashMap&& other) noexcept
    : count(other.count), cap(other.cap), containerType(other.containerType), vec(std::move(other.vec))
{
    other.count = 0;
    other.cap = 31;
    other.containerType = Container::Set;
    other.vec.resize(31);
}

template<typename Key, typename Value>
mystl::HashMap<Key, Value>& mystl::HashMap<Key, Value>::operator=(const HashMap& other)
{
    if (this != &other) 
    {
        clear(); 
        count = other.count;
        cap = other.cap;
        containerType = other.containerType;
        vec.resize(cap);
        for (std::size_t i = 0; i < other.vec.size(); ++i)
        {
            const mystl::ListNode<Node<Key, Value>>* cur = other.vec[i].begin();
            while (cur != nullptr)
            {
                vec[i].push_front(Node<Key, Value>(cur->val.key, cur->val.value[0], cur->val.cType));
                if (containerType == Container::MultiMap || containerType == Container::MultiSet)
                {
                    mystl::ListNode<Node<Key, Value>>* nodePtr = vec[i].begin();
                    while (nodePtr->next != nullptr)
                    {
                        nodePtr = nodePtr->next;
                    }
                    for (std::size_t j = 1; j < cur->val.value.size(); ++j)
                    {
                        nodePtr->val.value.push_back(cur->val.value[j]);
                    }
                }
                cur = cur->next; 
            }
        }
    }
    return *this;
}

template<typename Key, typename Value>
mystl::HashMap<Key, Value>& mystl::HashMap<Key, Value>::operator=(HashMap&& other) noexcept
{
    if (this != &other) 
    {
        clear();
        count = other.count;
        cap = other.cap;
        containerType = other.containerType;
        vec = std::move(other.vec);
        other.count = 0;
        other.cap = 31; 
        other.containerType = Container::Set; 
        other.vec.resize(31);
    }
    return *this;
}

template<typename Key, typename Value>
std::size_t mystl::HashMap<Key, Value>::hashFunction(const Key& key) const
{   
    return std::hash<Key>()(key) % cap;            
}

template<typename Key, typename Value>
bool mystl::HashMap<Key, Value>::isPrime(int num) const
{
    if(num <= 1)
    {
        return false;
    }
    if(num == 2 || num == 3)
    {
        return true;
    }
    for(int i = 2 ; i * i <= num ; i++)
    {
        if(num % i == 0)
        {
            return false;
        }
    }
    return true;
}

template<typename Key, typename Value>
int mystl::HashMap<Key, Value>::nextPrime(int num) const
{
    if(num <= 1)
    {
        return 2;
    }
    num++;
    while(!isPrime(num))
    {
        num++;
    }
    return num;
}

template<typename Key, typename Value>
void mystl::HashMap<Key, Value>::resize()
{
    cap = nextPrime(cap * 2);
    mystl::Vector<mystl::ForwardList<Node<Key, Value>>> tempVec(cap);
    for (const auto& list : vec) 
    {
        for (const auto& node : list) 
        {
            std::size_t index = hashFunction(node.val.key);
            tempVec[index].push_front(node.val);
        }
    }
    vec = std::move(tempVec);
}

template<typename Key, typename Value>
void mystl::HashMap<Key, Value>::insert(const Key& key, const Value& val)
{
    std::size_t index = hashFunction(key);
    auto& list = vec[index];
    for (auto it = list.begin(); it != list.end(); it = it -> next) 
    {
        auto& node = *it;
        if (node.val.key == key) 
        {
            if (containerType == Container::Set || containerType == Container::Map) 
            {
                node.val.value = {val}; 
            } 
            else 
            {
                node.val.value.push_back(val);
                ++count;
            }
            return;
        }
    }
    list.push_front(Node<Key, Value>(key, val, containerType));
    if (++count > cap * 0.75) 
    {
        resize();
    }
}

template<typename Key, typename Value>
void mystl::HashMap<Key, Value>::remove(const Key& key)
{
    std::size_t index = hashFunction(key);
    auto& list = vec[index];
    auto it = list.begin();
    while(it != list.end())
    {
        if((it->val).key == key)
        {
            count -= (it -> val).value.size();
            it = list.erase(it);   
        }
        else
        {
            it = it -> next;
        }
    }
}

template<typename Key, typename Value>
std::size_t mystl::HashMap<Key, Value>::find(const Key& key) const
{
    std::size_t index = hashFunction(key);
    const auto& list = vec[index];
    std::size_t occurrences = 0;
    for (auto it = list.begin(); it != list.end(); it = it -> next)
    {
        if ((it->val).key == key)
        {
            occurrences += (it->val).value.size();
        }
    }
    return occurrences;
}


template<typename Key, typename Value>
void mystl::HashMap<Key, Value>::print() const 
{
    for (const auto& list : vec) 
    {
        if(list.empty()) continue;
        for (const auto* node = list.begin() ; node != list.end() ; node = node->next) 
        {
            std::cout << "Key: " << (node->val).key << " ";
            switch ((node->val).cType) 
            {
                case Container::Map:
                    std::cout << ", Value: " << (node->val).value[0];
                    break;
                case Container::MultiMap:
                    std::cout << ", Values: [";
                    for (std::size_t i = 0; i < (node->val).value.size(); ++i) 
                    {
                        if (i != 0) 
                        {
                            std::cout << ", ";
                        }
                        std::cout << (node->val).value[i];
                    }
                    std::cout << "]";
                    break;
                case Container::Set:
                    break;
                case Container::MultiSet:
                    for (std::size_t i = 1; i < (node->val).value.size(); ++i) 
                    {
                        if (i != 0) 
                        {
                            std::cout << ", ";
                        }
                        std::cout << (node->val).value[i];
                    }
                    break;
            }
            std::cout << std::endl;
        }
    }
}

template<typename Key, typename Value>
void mystl::HashMap<Key, Value>::clear()
{
    for (auto& list : vec) 
    {
        list.clear();
    }
    count = 0;
}

template<typename Key, typename Value>
mystl::HashMap<Key, Value>::~HashMap()
{
    clear();
}

#endif // HASH_TABLE_H
