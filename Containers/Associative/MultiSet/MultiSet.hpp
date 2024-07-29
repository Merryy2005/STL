#ifndef MULTISET_H
#define MULTISET_H

#include "C:\STL\Containers\Associative\BST.hpp"
#include <iostream>

namespace mystl
{
    template<typename Key>
    class Multiset : public BST<Key, Key>
    {
        public:
            Multiset();
            ~Multiset();
            Multiset(const Multiset& other);
            Multiset(Multiset&& other) noexcept;
            Multiset& operator=(const Multiset& other);
            Multiset& operator=(Multiset&& other) noexcept;
            void insert(const Key& k);
            void emplace(Key&& k);
            bool contains(const Key& k) const;
            std::size_t count(const Key& k) const;
            std::size_t size() const;
            void erase(const Key& k);
            void print() const;
            Key* begin() const;
            Key* end() const;
            void clear();
            bool empty() const;
            Node<Key, Key>* lower_bound(const Key& k) const;
            Node<Key, Key>* upper_bound(const Key& k) const;
        private:
            Node<Key, Key>* copyNodes(const Node<Key, Key>* node);
            std::size_t countNodes(Node<Key, Key>* node) const;
            Node<Key, Key>* eraseNode(Node<Key, Key>*& node, const Key& k);
            Node<Key, Key>* findMin(Node<Key, Key>* node);
    };
}

template<typename Key>
mystl::Multiset<Key>::Multiset() : BST<Key, Key>(Container::MultiSet) {}

template<typename Key>
mystl::Multiset<Key>::~Multiset() 
{
    this->clear();
}

template<typename Key>
mystl::Multiset<Key>::Multiset(const Multiset& other) : BST<Key, Key>(Container::MultiSet) 
{
    this->root = copyNodes(other.root);
}

template<typename Key>
mystl::Multiset<Key>::Multiset(Multiset&& other) noexcept : BST<Key, Key>(Container::MultiSet) 
{
    this->root = other.root;
    other.root = nullptr;
}

template<typename Key>
mystl::Multiset<Key>& mystl::Multiset<Key>::operator=(const Multiset& other) 
{
    if (this != &other) 
    {
        this->clear();
        this->root = copyNodes(other.root);
    }
    return *this;
}

template<typename Key>
mystl::Multiset<Key>& mystl::Multiset<Key>::operator=(Multiset&& other) noexcept 
{
    if (this != &other) 
    {
        this->clear();
        this->root = other.root;
        other.root = nullptr;
    }
    return *this;
}

template<typename Key>
void mystl::Multiset<Key>::insert(const Key& k) 
{
    BST<Key, Key>::insert(this->root, k, k);
}

template<typename Key>
void mystl::Multiset<Key>::emplace(Key&& k) 
{
    insert(std::move(k));
}

template<typename Key>
bool mystl::Multiset<Key>::contains(const Key& k) const 
{
    return this->find(k);
}

template<typename Key>
std::size_t mystl::Multiset<Key>::count(const Key& k) const 
{
    Node<Key, Key>* node = this->find(this->root, k);
    return node ? node->value.size() : 0;
}

template<typename Key>
std::size_t mystl::Multiset<Key>::size() const 
{
    return countNodes(this->root);
}

template<typename Key>
void mystl::Multiset<Key>::erase(const Key& k) 
{
    this->root = eraseNode(this->root, k);
}

template<typename Key>
void mystl::Multiset<Key>::print() const 
{
    this->inOrderTraversal(this->root);
    std::cout << std::endl;
}

template<typename Key>
Key* mystl::Multiset<Key>::begin() const
{
    Node<Key, Key>* node = this->root;
    if (!node) return nullptr;
    while (node->left) 
    {
        node = node->left;
    }
    return &(node->key);
}

template<typename Key>
Key* mystl::Multiset<Key>::end() const
{
    return nullptr;
}

template<typename Key>
void mystl::Multiset<Key>::clear()
{
    BST<Key, Key>::clear();
}

template<typename Key>
bool mystl::Multiset<Key>::empty() const
{
    return this->root == nullptr;
}

template<typename Key>
mystl::Node<Key, Key>* mystl::Multiset<Key>::lower_bound(const Key& k) const 
{
    return this->BST<Key, Key>::lower_bound(k);
}

template<typename Key>
mystl::Node<Key, Key>* mystl::Multiset<Key>::upper_bound(const Key& k) const 
{
    return this->BST<Key, Key>::upper_bound(this->root, k);
}

template<typename Key>
mystl::Node<Key, Key>* mystl::Multiset<Key>::copyNodes(const Node<Key, Key>* node) 
{
    if (!node) return nullptr;
    Node<Key, Key>* newNode = new Node<Key, Key>(node->key, node->value[0], Container::MultiSet);
    newNode->value = node->value;
    newNode->left = copyNodes(node->left);
    newNode->right = copyNodes(node->right);
    return newNode;
}

template<typename Key>
std::size_t mystl::Multiset<Key>::countNodes(Node<Key, Key>* node) const 
{
    if (!node) return 0;
    return node->value.size() + countNodes(node->left) + countNodes(node->right);
}

template<typename Key>
mystl::Node<Key, Key>* mystl::Multiset<Key>::eraseNode(Node<Key, Key>*& node, const Key& k) 
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
            Node<Key, Key>* temp = node->right;
            delete node;
            return temp;
        } 
        else if (!(node->right)) 
        {
            Node<Key, Key>* temp = node->left;
            delete node;
            return temp;
        }
        Node<Key, Key>* temp = this->findMin(node->right);
        node->key = temp->key;
        node->value = temp->value;
        node->right = eraseNode(node->right, temp->key);
    }
    return node;
}

template<typename Key>
mystl::Node<Key, Key>* mystl::Multiset<Key>::findMin(Node<Key, Key>* node) 
{
    while (node && node->left) 
    {
        node = node->left;
    }
    return node;
}

#endif // MULTISET_H
