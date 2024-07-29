#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "C:\STL\Containers\Sequence\Vector\Vector.hpp"


namespace mystl
{
    template<typename T>
    class ForwardList
    {
        class Node
        {
            private:
                T val;
                Node* next;
            public:
                Node();
                Node(const T&);
                T& operator*();
                const T& operator*() const;
                ~Node();
            friend class ForwardList;
        };
        private:
            Node* head;
        public:
            ForwardList();
            ForwardList(const ForwardList&);
            ForwardList(ForwardList&&);
            ForwardList& operator=(const ForwardList&);
            ForwardList& operator=(ForwardList&&);
            T& front();
            const T& front() const;
            Node* begin() noexcept;
            const Node* begin() const noexcept;
            const Node* cbegin() const noexcept;
            Node* end() noexcept;
            const Node* end() const noexcept;
            const Node* cend() const noexcept;
            bool empty() const noexcept;
            void clear() noexcept;
            std::size_t size() const;
            void insert(std::size_t , const T&);
            void erase(std::size_t);
            void push_back(const T&);
            void pop_back();
            void push_front(const T&);
            void pop_front();
            void print() const;
            void createLoop(std::size_t);
            bool hasLoop() const;
            void reverseList();
            const T& findNthlastElem(std::size_t) const;
            ~ForwardList();
    };
}

template<typename T>
mystl::ForwardList<T>::Node::Node() : val(T()) , next(nullptr)
{

}

template<typename T>
mystl::ForwardList<T>::Node::Node(const T& val) : val(val) , next(nullptr)
{

}

template<typename T>
T& mystl::ForwardList<T>::Node::operator*()
{
    return val;
}

template<typename T>
const T& mystl::ForwardList<T>::Node::operator*() const
{
    return val;
}

template<typename T>
mystl::ForwardList<T>::Node::~Node()
{

}

template<typename T>
mystl::ForwardList<T>::ForwardList() : head(nullptr)
{

}

template<typename T>
mystl::ForwardList<T>::ForwardList(const ForwardList<T>& other) : head(nullptr)
{
    Node* cur = other.head;
    while (cur) 
    {
        push_back(cur->val);
        cur = cur -> next;
    }
}

template<typename T>
mystl::ForwardList<T>::ForwardList(ForwardList&& other) : head(other.head)
{
    other.head = nullptr;
}

template<typename T>
mystl::ForwardList<T>& mystl::ForwardList<T>::operator=(const ForwardList<T>& other)
{
    if(this != &other)
    {
        clear();
        Node* cur = other.head;
        while (cur) 
        {
            push_back(cur->val);
            cur = cur -> next;
        }
    }
    return *this;
}

template<typename T>
mystl::ForwardList<T>& mystl::ForwardList<T>::operator=(ForwardList<T>&& other)
{
    if(this != &other)
    {
        clear();
        head = other.head;
        other.head = nullptr;
    }
    return *this;
}

template<typename T>
T& mystl::ForwardList<T>::front() 
{
    if (!head) 
    {
        throw std::out_of_range("ForwardList is empty");
    }
    return head->val;
}

template<typename T>
const T& mystl::ForwardList<T>::front() const 
{
    if (!head) 
    {
        throw std::out_of_range("ForwardList is empty");
    }
    return head->val;
}

template<typename T>
typename mystl::ForwardList<T>::Node* mystl::ForwardList<T>::begin() noexcept
{
    return head;
}

template<typename T>
const typename mystl::ForwardList<T>::Node* mystl::ForwardList<T>::begin() const noexcept
{
    return head;
}

template<typename T>
const typename mystl::ForwardList<T>::Node* mystl::ForwardList<T>::cbegin() const noexcept
{
    return head;
}

template<typename T>
typename mystl::ForwardList<T>::Node* mystl::ForwardList<T>::end() noexcept
{
    return nullptr;
}

template<typename T>
const typename mystl::ForwardList<T>::Node* mystl::ForwardList<T>::end() const noexcept
{
    return nullptr;
}

template<typename T>
const typename mystl::ForwardList<T>::Node* mystl::ForwardList<T>::cend() const noexcept
{
    return nullptr;
}

template<typename T>
bool mystl::ForwardList<T>::empty() const noexcept
{
    return head == nullptr;
}

template<typename T>
void mystl::ForwardList<T>::clear() noexcept
{
    mystl::Vector<Node*> deleted;
    while(head != nullptr)
    {
        Node* tmp = head;
        bool isDeleted = false;
        for(std::size_t i = 0 ; i < deleted.size() ; i++)
        {
            if(tmp == deleted[i])
            {
                isDeleted = true;
                break;
            }
        }
        deleted.push_back(tmp);
        if(isDeleted)
        {
            head = nullptr;
            return;
        }
        head = head -> next;
        delete tmp;
        tmp = nullptr;
    }
    head = nullptr;
    deleted.clear();  
    return;
}

template<typename T>
std::size_t mystl::ForwardList<T>::size() const
{
    Node* tmp = head;
    std::size_t s = 0;
    while(tmp != nullptr)
    {
        s++;
        tmp = tmp -> next;
    }
    return s;
}

template<typename T>
void mystl::ForwardList<T>::insert(std::size_t pos , const T& val)
{
    if(pos == 0)
    {
        push_front(val);
        return;
    }
    Node* ptr = new Node(val);
    std::size_t ind = 0;
    Node* tmp = head;
    Node* tmp1 = nullptr;
    while(tmp != nullptr && ind < pos)
    {
        ind++;
        tmp1 = tmp;
        tmp = tmp -> next;
    }
    if(ind == pos)
    {
        tmp1 -> next = ptr;
        ptr -> next = tmp;
    }
    else
    {
        throw std::out_of_range("out of range");
    }
    return;
}

template<typename T>
void mystl::ForwardList<T>::erase(std::size_t pos)
{
    if(pos == 0)
    {
        pop_front();
        return;
    }
    std::size_t ind = 0;
    Node* tmp = head;
    Node* tmp1 = nullptr;
    while(tmp != nullptr && ind < pos)
    {
        ind++;
        tmp1 = tmp;
        tmp = tmp -> next;
    }
    if(ind == pos && tmp != nullptr)
    {
        tmp1 -> next = tmp -> next;
        delete tmp;
    }
    else
    {
        throw std::out_of_range("out of range");
    }
    return;
}

template<typename T>
void mystl::ForwardList<T>::push_back(const T& val)
{
    Node* ptr = new Node(val);
    if(head == nullptr)
    {
        head = ptr;
    }
    else
    {
        Node* tmp = head;
        while(tmp -> next != nullptr)
        {
            tmp = tmp -> next; 
        }
        tmp -> next = ptr; 
    }
    return;
}

template<typename T>
void mystl::ForwardList<T>::pop_back()
{
    if(head == nullptr)
    {
        throw std::runtime_error("List is empty. Cannot pop from an empty list.");
    }
    else if(head -> next == nullptr)
    {
        delete head;
        head = nullptr;
    }
    else
    {
        Node* tmp = head;
        Node* tmp1 = nullptr;
        while(tmp -> next != nullptr)
        {
            tmp1 = tmp;
            tmp = tmp -> next; 
        }
        tmp1 -> next = nullptr;
        delete tmp;
    }
}

template<typename T>
void mystl::ForwardList<T>::push_front(const T& val)
{
    Node* ptr = new Node(val);
    ptr -> next = head;
    head = ptr;
}

template<typename T>
void mystl::ForwardList<T>::pop_front()
{
    if(head == nullptr)
    {
        throw std::runtime_error("List is empty. Cannot pop from an empty list.");
    }
    else
    {
        Node* tmp = head;
        head = head -> next;
        delete tmp;
    }
}

template<typename T>
void mystl::ForwardList<T>::print() const
{
    mystl::Vector<Node*> printed;
    Node* tmp = head;
    while(tmp != nullptr)
    {
        std::cout << tmp -> val << " ";
        bool isPrinted = false;
        for(int i = 0 ; i < printed.size() ; i++)
        {
            if(tmp == printed[i])
            {
                isPrinted = true;
                break;
            }
        }
        printed.push_back(tmp);
        if(isPrinted)
        {
            std::cout << std::endl;
            return;
        }
        tmp = tmp -> next;
    }
    std::cout << std::endl;
    printed.clear();
    return;
}

template<typename T>
void  mystl::ForwardList<T>::createLoop(std::size_t pos)
{
    std::size_t ind = 0;
    Node* ptr = nullptr;
    Node* tmp = head;
    Node* tmp1 = nullptr;
    while(tmp != nullptr)
    {
        if(ind == pos)
        {
            ptr = tmp;
        }
        tmp1 = tmp;
        tmp = tmp -> next;
        ind++;
    }
    if(ptr == nullptr)
    {
        std::cout << "Couldn't create cycle" << std::endl;
        return;
    }
    tmp1 -> next = ptr;
    return;
}

template<typename T>
bool mystl::ForwardList<T>::hasLoop() const
{
    Node* ptr1 = head;
    Node* ptr2 = head;
    while(ptr1 && ptr2 && ptr2 -> next)
    {
        ptr1 = ptr1 -> next;
        ptr2 = ptr2 -> next -> next;
        if(ptr1 == ptr2)
        {
            return true;
        }
    }
    return false;
}

template<typename T>
void mystl::ForwardList<T>::reverseList()
{
    Node* tmp = head;
    Node* tmp1 = nullptr;
    while(tmp != nullptr)
    {
        Node* tmp2 = tmp -> next; 
        tmp -> next = tmp1;
        tmp1 = tmp;
        tmp = tmp2;
    }
    head = tmp1;
    return;
}

template<typename T>
const T& mystl::ForwardList<T>::findNthlastElem(std::size_t n) const
{
    Node* tmp1 = head;
    Node* tmp2 = head;
    for(std::size_t i = 0 ; i < n ; i++)
    {
        if(tmp2 == nullptr)
        {
            throw std::out_of_range("List size is smaller than the element");
        }
        tmp2 = tmp2 -> next;
    }
    while(tmp2 != nullptr)
    {
        tmp1 = tmp1 -> next;
        tmp2 = tmp2 -> next;
    }
    return tmp1 -> val;
}

template<typename T>
mystl::ForwardList<T>::~ForwardList()
{
    clear();
}
#endif //LIST_H