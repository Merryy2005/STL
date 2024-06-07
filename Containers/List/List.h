#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <vector>


namespace mystl
{
    template<typename T>
    class List
    {
        class Node
        {
            private:
                T val;
                Node* next;
                Node* prev;
            public:
                Node();
                Node(const T&);
                ~Node();
            friend class List;
        };
        private:
            Node* head;
            Node* tail;
        public:
            List();
            void push_back(const T&);
            void pop_back();
            void push_front(const T&);
            void pop_front();
            void insert(int , const T&);
            void print() const;
            void createLoop(int);
            bool hasLoop() const;
            void reverseList();
            T findNthlastElem(int) const;
            ~List();
    };
}

template<typename T>
mystl::List<T>::Node::Node() : val(T()) , next(nullptr) , prev(nullptr)
{

}

template<typename T>
mystl::List<T>::Node::Node(const T& val) : val(val) , next(nullptr) , prev(nullptr)
{

}

template<typename T>
mystl::List<T>::Node::~Node()
{

}

template<typename T>
mystl::List<T>::List() : head(nullptr) , tail(nullptr)
{

}

template<typename T>
void mystl::List<T>::push_back(const T& val)
{
    Node* ptr = new Node(val);
    if(tail == nullptr)
    {
        head = ptr;
        tail = ptr;
    }
    else
    {
        tail -> next = ptr;
        ptr -> prev = tail;
        ptr -> next = nullptr;
        tail = ptr;
    }
}

template<typename T>
void mystl::List<T>::pop_back()
{
    if(tail == nullptr)
    {
        throw std::runtime_error("List is empty. Cannot pop from an empty list.");
    }
    else
    {
        if(head == tail)
        {
            delete tail;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node* tmp = tail;
            tail = tail -> prev;
            tail -> next = nullptr;
            delete tmp;
        }
    }
}

template<typename T>
void mystl::List<T>::push_front(const T& val)
{
    Node* ptr = new Node(val);
    if(head == nullptr)
    {
        head = ptr;
        tail = ptr;
    }
    else
    {
        head -> prev = ptr;
        ptr -> next = head;
        ptr -> prev = nullptr;
        head = ptr;
    }
}

template<typename T>
void mystl::List<T>::pop_front()
{
    if(head == nullptr)
    {
        throw std::runtime_error("List is empty. Cannot pop from an empty list.");
    }
    else
    {
        if(head == tail)
        {
            delete tail;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node* tmp = head;
            head = head -> next;
            head -> prev = nullptr;
            delete tmp;
        }
    }
}

template<typename T>
void mystl::List<T>::insert(int pos, const T& val)
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
    Node* tmp1 = head;
    Node* tmp0 = nullptr;
    for(int i = 0 ; i < pos ; i++)
    {
        if(tmp1 == nullptr)
        {
            throw std::runtime_error("List is smaller. Can't do insertion");
        }
        tmp0 = tmp1;
        tmp1 = tmp1 -> next;
    }
    if(tmp0 == tail)
    {
        push_back(val);
    }
    else
    {
        tmp1 -> prev = ptr;
        ptr -> next = tmp1;
        tmp0 -> next = ptr;
        ptr -> prev = tmp0;
    }
    return;
}

template<typename T>
void mystl::List<T>::print() const
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
    printed.clear();
    return;
}

template<typename T>
void  mystl::List<T>::createLoop(int pos)
{
    int ind = -1;
    Node* ptr = nullptr;
    Node* tmp = head;
    while(tmp != nullptr)
    {
        ind++;
        if(ind == pos)
        {
            ptr = tmp;
            break;
        }
        tmp = tmp -> next;
    }
    if(ptr == nullptr)
    {
        std::cout << "Couldn't create cycle" << std::endl;
        return;
    }
    tail -> next = ptr;
    ptr -> prev = tail;
    return;
}

template<typename T>
bool mystl::List<T>::hasLoop() const
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
void mystl::List<T>::reverseList()
{
    if(head != tail)
    {
        Node* tmp = head;
        head = tail;
        Node* first = head;
        while(first != nullptr)
        {
            std::swap(first -> prev , first -> next);
            first = first -> next;
        }
        tail = tmp;
    }
    return;
}

template<typename T>
T mystl::List<T>::findNthlastElem(int n) const
{
    Node* tmp = tail;
    for(int i = 0 ; i < n ; i++)
    {
        if(tmp == nullptr)
        {
            std::cout << "List size is smaller than the element";
            return T();
        }
        tmp = tmp -> prev;
    }
    return tmp -> val;
}

template<typename T>
mystl::List<T>::~List()
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
    deleted.clear();
}
#endif //LIST_H