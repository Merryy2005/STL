#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <vector>


namespace mystl
{
    template<typename T>
    class SingleLinkedList
    {
        class Node
        {
            private:
                T val;
                Node* next;
            public:
                Node();
                Node(const T&);
                ~Node();
            friend class SingleLinkedList;
        };
        private:
            Node* head;
        public:
            SingleLinkedList();
            void push_back(const T&);
            void pop_back();
            void push_front(const T&);
            void pop_front();
            void insert(int , const T&);
            void print() const;
            void createLoop(int);
            bool hasLoop() const;
            void reverseList();
            T findElem(int) const;
            ~SingleLinkedList();
    };
}

template<typename T>
mystl::SingleLinkedList<T>::Node::Node() : val(T()) , next(nullptr)
{

}

template<typename T>
mystl::SingleLinkedList<T>::Node::Node(const T& val) : val(val) , next(nullptr)
{

}

template<typename T>
mystl::SingleLinkedList<T>::Node::~Node()
{

}

template<typename T>
mystl::SingleLinkedList<T>::SingleLinkedList() : head(nullptr)
{

}

template<typename T>
void mystl::SingleLinkedList<T>::push_back(const T& val)
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
}

template<typename T>
void mystl::SingleLinkedList<T>::pop_back()
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
void mystl::SingleLinkedList<T>::push_front(const T& val)
{
    Node* ptr = new Node(val);
    ptr -> next = head;
    head = ptr;
}

template<typename T>
void mystl::SingleLinkedList<T>::pop_front()
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
void mystl::SingleLinkedList<T>::insert(int pos, const T& val)
{
    if(pos < 0)
    {
        throw std::runtime_error("Can't do insertion on a negative position");
    }
    Node* ptr= new Node(val);
    if(pos == 0)
    {
        push_front(val);
        return;
    }
    Node* tmp = head;
    Node* tmp1 = nullptr;
    for(int i = 0 ; i < pos ; i++)
    {
        if(tmp == nullptr)
        {
            throw std::runtime_error("List is smaller. Can't do insertion");
        }
        tmp1 = tmp;
        tmp = tmp -> next;
    }
    tmp1 -> next = ptr;
    ptr -> next = tmp;
    return;
}

template<typename T>
void mystl::SingleLinkedList<T>::print() const
{
    std::vector<Node*> printed;
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
    return;
}

template<typename T>
void  mystl::SingleLinkedList<T>::createLoop(int pos)
{
    int ind = -1;
    Node* ptr = nullptr;
    Node* tmp = head;
    Node* tmp1 = nullptr;
    while(tmp != nullptr)
    {
        ind++;
        if(ind == pos)
        {
            ptr = tmp;
        }
        tmp1 = tmp;
        tmp = tmp -> next;
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
bool mystl::SingleLinkedList<T>::hasLoop() const
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
void mystl::SingleLinkedList<T>::reverseList()
{
    Node* tmp = head;
    std::vector<Node*> nodes;
    while(tmp != nullptr)
    {
        nodes.push_back(tmp);
        tmp = tmp -> next;
    }
    head = nodes.back();
    tmp = head;
    for(int i = nodes.size() - 2 ; i >= 0 ; i--)
    {   
        tmp -> next = nodes[i];
        tmp = tmp -> next;
    }
    tmp -> next = nullptr;
    return;
}

template<typename T>
T mystl::SingleLinkedList<T>::findElem(int n) const
{
    int size = 0;
    Node* tmp = head;
    while(tmp != nullptr)
    {
        tmp = tmp -> next;
        size++;
    }
    if(size < n)
    {
        throw std::runtime_error("List size is smaller than the element");
    }
    n = size - n - 1;
    int ind = -1;
    tmp = head;
    Node* tmp1 = nullptr;
    while(tmp != nullptr && ind < n)
    {
        tmp1 = tmp;
        tmp = tmp -> next;
        ind++;
    }
    return tmp1 -> val;
}

template<typename T>
mystl::SingleLinkedList<T>::~SingleLinkedList()
{
    std::vector<Node*> deleted;
    while(head != nullptr)
    {
        Node* tmp = head;
        bool isDeleted = false;
        for(int i = 0 ; i < deleted.size() ; i++)
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
            return;
        }
        delete tmp;
        tmp = nullptr;
        head = head -> next;
    }
}
#endif //LIST_H