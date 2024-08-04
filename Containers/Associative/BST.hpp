#ifndef BST_H
#define BST_H

#include <iostream>
#include "C:\STL\Containers\Sequence\Vector\Vector.hpp"

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
    class BST;

    template<typename Key , typename Value>
    class Node
    {
        public:
            Key key;
            mystl::Vector<Value> value;
            Node* left;
            Node* right;
            Container cType;
            Node(const Key& , const Value& , Container);
        friend class BST<Key, Value>;
    };

    template<typename Key , typename Value>
    class BST
    {
        protected:
            Node<Key , Value>* root;
            Container containerType;
            void insert(Node<Key, Value>*&, const Key& , const Value&);
            Node<Key, Value>* find(Node<Key, Value>* , const Key&) const;
            void inOrderTraversal(Node<Key, Value>*) const;
            void clear(Node<Key, Value>*);
            Node<Key, Value>* lower_bound(Node<Key, Value>*, const Key&) const;
            Node<Key, Value>* upper_bound(Node<Key, Value>*, const Key&) const;
        public:
            BST(Container);
            void insert(const Key& , const Value& = Value());
            bool find(const Key&) const;
            void print() const;
            void clear();
            Node<Key, Value>* lower_bound(const Key&) const;
            Node<Key, Value>* upper_bound(const Key&) const;
            ~BST();
    };
}

template<typename Key, typename Value>
mystl::Node<Key, Value>::Node(const Key& k, const Value& v, mystl::Container c) : key(k), value(), left(nullptr), right(nullptr) , cType(c) 
{
    value = mystl::Vector<Value>{v};
}

template<typename Key, typename Value>
mystl::BST<Key, Value>::BST(mystl::Container c)
    : root(nullptr), containerType(c)
{
}

template<typename Key, typename Value>
void mystl::BST<Key, Value>::insert(mystl::Node<Key , Value>*& node, const Key& k, const Value& v)
{
    if (!node) 
    {
        node = new Node<Key , Value>(k, v , containerType);
    } 
    else if (k < node->key) 
    {
        insert(node->left, k, v);
    } 
    else if (k > node->key)
    {
        insert(node->right, k, v);
    } 
    else 
    {
        if(containerType == Container::Set || containerType == Container::Map)
        {
            node->value = mystl::Vector<Value>{v};   
        }
        else
        {
            node->value.push_back(v);
        }
    }
}

template<typename Key, typename Value>
mystl::Node<Key, Value>* mystl::BST<Key, Value>::find(mystl::Node<Key, Value>* node, const Key& k) const
{
    if (!node) 
    {
        return nullptr; 
    }
    if (k < node->key) 
    {
        return find(node->left, k);
    } 
    else if (k > node->key) 
    {
        return find(node->right, k);
    } 
    else 
    {
        return node;
    }
}

template<typename Key, typename Value>
void mystl::BST<Key, Value>::inOrderTraversal(Node<Key, Value>* node) const 
{
    if (node != nullptr) 
    {
        inOrderTraversal(node->left);
        std::cout << "Key: " << node->key << " ";
        switch (containerType) 
        {
            case Container::Map:
                std::cout << ", Value: " << node->value[0];
                break;
            case Container::MultiMap:
                std::cout << ", Values: [";
                for (const auto& val : node->value) 
                {
                    std::cout << val << " ";
                }
                std::cout << "]";
                break;
            case Container::Set:
                break;
            case Container::MultiSet:
                for (int i = 0 ; i < node->value.size() - 1; i++) 
                {
                    std::cout << node->value[i] << " ";
                }
                break;
        }
        std::cout << std::endl;
        inOrderTraversal(node->right);
    }
}

template<typename Key, typename Value>
void mystl::BST<Key, Value>::clear(Node<Key, Value>* node) 
{
    if (node != nullptr) 
    {
        clear(node->left);  
        clear(node->right);  
        delete node;         
    }
}

template<typename Key, typename Value>
void mystl::BST<Key, Value>::insert(const Key& k, const Value& v)
{
    insert(root, k, v);
}

template<typename Key, typename Value>
bool mystl::BST<Key, Value>::find(const Key& k) const
{
    return find(root, k) != nullptr;
}

template<typename Key, typename Value>      
void mystl::BST<Key, Value>::print() const
{
    inOrderTraversal(root);
    std::cout << std::endl;
}

template<typename Key, typename Value>  
void mystl::BST<Key, Value>::clear()
{
    clear(root);
    root = nullptr;
}

template<typename Key, typename Value>
mystl::Node<Key, Value>* mystl::BST<Key, Value>::lower_bound(Node<Key, Value>* node, const Key& k) const 
{
    if (!node) 
    {
        return nullptr;
    }
    if (k < node->key) 
    {
        Node<Key, Value>* ans = lower_bound(node->left, k);
        if (ans) 
        {
            return ans;
        } 
        else 
        {
            return node;
        }
    } 
    else if (k > node->key) 
    {
        return lower_bound(node->right, k);
    } 
    else 
    {
        return node;
    }
}

template<typename Key, typename Value>
mystl::Node<Key, Value>* mystl::BST<Key, Value>::lower_bound(const Key& k) const 
{
    return lower_bound(root, k);
}

template<typename Key, typename Value>
mystl::Node<Key, Value>* mystl::BST<Key, Value>::upper_bound(Node<Key, Value>* node, const Key& k) const 
{
    if (!node) 
    {
        return nullptr;
    }
    if (k < node->key) 
    {
        Node<Key, Value>* ans = upper_bound(node->left, k);
        if (ans) 
        {
            return ans; 
        } 
        else 
        {
            return node;
        }
    } 
    else 
    {
        return upper_bound(node->right, k);
    }
}

template<typename Key, typename Value>
mystl::Node<Key, Value>* mystl::BST<Key, Value>::upper_bound(const Key& k) const 
{
    return upper_bound(root, k);
}

template<typename Key, typename Value>  
mystl::BST<Key, Value>::~BST()
{
    clear();
}

#endif //BST_H