#ifndef MULTIMAP_H
#define MULTIMAP_H

#include "C:\STL\Containers\Associative\BST.hpp"
#include <iostream>

namespace mystl
{
    template<typename Key, typename Value>
    class MultiMap : public BST<Key, Value>
    {
        public:
            MultiMap();
            ~MultiMap();
            MultiMap(const MultiMap& other);
            MultiMap(MultiMap&& other) noexcept;
            MultiMap& operator=(const MultiMap& other);
            MultiMap& operator=(MultiMap&& other) noexcept;
            void insert(const Key& k, const Value& v);
            void emplace(Key&& k, Value&& v);
            bool contains(const Key& k) const;
            std::size_t count(const Key& k) const;
            void erase(const Key& k);
            void print() const;
            Node<Key, Value>* begin() const;
            Node<Key, Value>* end() const;
            bool empty() const;
            std::size_t size() const;
            void clear();
            Node<Key, Value>* lower_bound(const Key& k) const;
            Node<Key, Value>* upper_bound(const Key& k) const;
            Node<Key, Value>* find(const Key& k) const;
        private:
            Node<Key, Value>* copyNodes(const Node<Key, Value>* node);
            Node<Key, Value>* findNode(const Key& k) const;
            std::size_t countNodes(Node<Key, Value>* node) const;
            Node<Key, Value>* eraseNode(Node<Key, Value>* node, const Key& k);
            Node<Key, Value>* findMin(Node<Key, Value>* node) const;
    };
}

template<typename Key, typename Value>
mystl::MultiMap<Key, Value>::MultiMap() : BST<Key, Value>(Container::MultiMap) {}

template<typename Key, typename Value>
mystl::MultiMap<Key, Value>::~MultiMap() 
{
    this->clear();
}

template<typename Key, typename Value>
mystl::MultiMap<Key, Value>::MultiMap(const MultiMap& other) : BST<Key, Value>(Container::MultiMap) 
{
    this->root = copyNodes(other.root);
}

template<typename Key, typename Value>
mystl::MultiMap<Key, Value>::MultiMap(MultiMap&& other) noexcept : BST<Key, Value>(Container::MultiMap) 
{
    this->root = other.root;
    other.root = nullptr;
}

template<typename Key, typename Value>
mystl::MultiMap<Key, Value>& mystl::MultiMap<Key, Value>::operator=(const MultiMap& other) 
{
    if (this != &other) 
    {
        this->clear();
        this->root = copyNodes(other.root);
    }
    return *this;
}

template<typename Key, typename Value>
mystl::MultiMap<Key, Value>& mystl::MultiMap<Key, Value>::operator=(MultiMap&& other) noexcept 
{
    if (this != &other) 
    {
        this->clear();
        this->root = other.root;
        other.root = nullptr;
    }
    return *this;
}

template<typename Key, typename Value>
void mystl::MultiMap<Key, Value>::insert(const Key& k, const Value& v) 
{
    BST<Key, Value>::insert(k, v);
}

template<typename Key, typename Value>
void mystl::MultiMap<Key, Value>::emplace(Key&& k, Value&& v) 
{
    this->insert(std::move(k), std::move(v));
}

template<typename Key, typename Value>
bool mystl::MultiMap<Key, Value>::contains(const Key& k) const 
{
    return this->find(k);
}

template<typename Key, typename Value>
std::size_t mystl::MultiMap<Key, Value>::count(const Key& k) const 
{
    mystl::Node<Key, Value>* node = findNode(k);
    if (node) 
    {
        return node->value.size();
    }
    return 0;
}

template<typename Key, typename Value>
void mystl::MultiMap<Key, Value>::erase(const Key& k) 
{
    this->root = this->eraseNode(this->root, k);
}

template<typename Key, typename Value>
void mystl::MultiMap<Key, Value>::print() const 
{
    this->inOrderTraversal(this->root);
    std::cout << std::endl;
}

template<typename Key, typename Value>
mystl::Node<Key, Value>* mystl::MultiMap<Key, Value>::begin() const
{
    Node<Key, Value>* node = this->root;
    while (node && node->left) 
    {
        node = node->left;
    }
    return node;
}

template<typename Key, typename Value>
mystl::Node<Key, Value>* mystl::MultiMap<Key, Value>::end() const
{
    return nullptr;
}

template<typename Key, typename Value>
bool mystl::MultiMap<Key, Value>::empty() const 
{
    return this->root == nullptr;
}

template<typename Key, typename Value>
std::size_t mystl::MultiMap<Key, Value>::size() const 
{
    return countNodes(this->root);
}

template<typename Key, typename Value>
void mystl::MultiMap<Key, Value>::clear() 
{
    this->BST<Key, Value>::clear();
}

template<typename Key, typename Value>
mystl::Node<Key, Value>* mystl::MultiMap<Key, Value>::lower_bound(const Key& k) const 
{
    return this->BST<Key, Value>::lower_bound(k);
}

template<typename Key, typename Value>
mystl::Node<Key, Value>* mystl::MultiMap<Key, Value>::upper_bound(const Key& k) const 
{
    return this->BST<Key, Value>::upper_bound(k);
}

template<typename Key, typename Value>
mystl::Node<Key, Value>* mystl::MultiMap<Key, Value>::find(const Key& k) const 
{
    Node<Key, Value>* node = this->root;
    while (node) 
    {
        if (k < node->key) 
        {
            node = node->left;
        } 
        else if (k > node->key) 
        {
            node = node->right;
        } 
        else 
        {
            return node;
        }
    }
    return nullptr;
}

template<typename Key, typename Value>
mystl::Node<Key, Value>* mystl::MultiMap<Key, Value>::copyNodes(const Node<Key, Value>* node) 
{
    if (!node) return nullptr;
    Node<Key, Value>* newNode = new Node<Key, Value>(node->key, node->value[0], Container::MultiMap);
    newNode->value = node->value;
    newNode->left = copyNodes(node->left);
    newNode->right = copyNodes(node->right);
    return newNode;
}

template<typename Key, typename Value>
mystl::Node<Key, Value>* mystl::MultiMap<Key, Value>::findNode(const Key& k) const 
{
    return this->find(k);
}

template<typename Key, typename Value>
std::size_t mystl::MultiMap<Key, Value>::countNodes(Node<Key, Value>* node) const 
{
    if (!node) return 0;
    return node->value.size() + countNodes(node->left) + countNodes(node->right);
}

template<typename Key, typename Value>
mystl::Node<Key, Value>* mystl::MultiMap<Key, Value>::eraseNode(Node<Key, Value>* node, const Key& k) 
{
    if (!node) return nullptr;
    if (k < node->key) 
    {
        node->left = eraseNode(node->left, k);
    } 
    else if (k > node->key) 
    {
        node->right = eraseNode(node->right, k);
    } 
    else 
    {
        if (!(node->left)) 
        {
            Node<Key, Value>* temp = node->right;
            delete node;
            return temp;
        } 
        else if (!(node->right)) 
        {
            Node<Key, Value>* temp = node->left;
            delete node;
            return temp;
        }
        Node<Key, Value>* temp = findMin(node->right);
        node->key = temp->key;
        node->value = temp->value;
        node->right = eraseNode(node->right, temp->key);
    }
    return node;
}

template<typename Key, typename Value>
mystl::Node<Key, Value>* mystl::MultiMap<Key, Value>::findMin(Node<Key, Value>* node) const 
{
    while (node && node->left) 
    {
        node = node->left;
    }
    return node;
}

#endif // MULTIMAP_H
