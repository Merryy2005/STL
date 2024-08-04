#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "C:\STL\Containers\Sequence\Vector\Vector.hpp"


namespace mystl
{
    template<typename T>
    class ForwardList;

    template<typename T>
    class ListNode
    {
        public:
            T val;
            ListNode* next;
        public:
            ListNode();
            ListNode(const T&);
            T& operator*();
            const T& operator*() const;
            ~ListNode();
        friend class mystl::ForwardList<T>;
    };
    template<typename T>
    class ForwardList
    {
        private:
            mystl::ListNode<T>* head;
        public:
            ForwardList();
            ForwardList(const ForwardList&);
            ForwardList(ForwardList&&);
            ForwardList& operator=(const ForwardList&);
            ForwardList& operator=(ForwardList&&);
            T& front();
            const T& front() const;
            ListNode<T>* begin() noexcept;
            const ListNode<T>* begin() const noexcept;
            ListNode<T>* end() noexcept;
            const ListNode<T>* end() const noexcept;
            bool empty() const noexcept;
            void clear() noexcept;
            std::size_t size() const;
            void insert(std::size_t , const T&);
            void erase(std::size_t);
            mystl::ListNode<T>* erase(ListNode<T>* node);
            void remove(const T& value); 
            void removeIf(bool (*pred)(const T&)); 
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
mystl::ListNode<T>::ListNode() : val(T()) , next(nullptr)
{

}

template<typename T>
mystl::ListNode<T>::ListNode(const T& val) : val(val) , next(nullptr)
{

}

template<typename T>
T& mystl::ListNode<T>::operator*()
{
    return val;
}

template<typename T>
const T& mystl::ListNode<T>::operator*() const
{
    return val;
}

template<typename T>
mystl::ListNode<T>::~ListNode()
{

}

template<typename T>
mystl::ForwardList<T>::ForwardList() : head(nullptr)
{

}

template<typename T>
mystl::ForwardList<T>::ForwardList(const ForwardList<T>& other) : head(nullptr)
{
    mystl::ListNode<T>* cur = other.head;
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
        mystl::ListNode<T>* cur = other.head;
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
typename mystl::ListNode<T>* mystl::ForwardList<T>::begin() noexcept
{
    return head;
}

template<typename T>
const typename mystl::ListNode<T>* mystl::ForwardList<T>::begin() const noexcept
{
    return head;
}

template<typename T>
typename mystl::ListNode<T>* mystl::ForwardList<T>::end() noexcept
{
    return nullptr;
}

template<typename T>
const typename mystl::ListNode<T>* mystl::ForwardList<T>::end() const noexcept
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
    mystl::Vector<mystl::ListNode<T>*> deleted;
    while(head != nullptr)
    {
        mystl::ListNode<T>* tmp = head;
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
    mystl::ListNode<T>* tmp = head;
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
    mystl::ListNode<T>* ptr = new mystl::ListNode<T>(val);
    std::size_t ind = 0;
    mystl::ListNode<T>* tmp = head;
    mystl::ListNode<T>* tmp1 = nullptr;
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
    mystl::ListNode<T>* tmp = head;
    mystl::ListNode<T>* tmp1 = nullptr;
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
mystl::ListNode<T>* mystl::ForwardList<T>::erase(mystl::ListNode<T>* node)
{
    if (head == nullptr)
    {
        throw std::runtime_error("List is empty. Cannot erase from an empty list.");
    }
    if (head == node)
    {
        head = head->next;
        mystl::ListNode<T>* nextNode = head;  
        delete node;
        return nextNode;
    }
    mystl::ListNode<T>* current = head;
    while (current != nullptr && current->next != node)
    {
        current = current->next;
    }
    if (current != nullptr)
    {
        mystl::ListNode<T>* nextNode = node->next; 
        current->next = nextNode;
        delete node;
        return nextNode;
    }
    else
    {
        throw std::out_of_range("Node not found in the list.");
    }
}

template<typename T>
void mystl::ForwardList<T>::remove(const T& value) 
{
    while (head && head->val == value) 
    {
        mystl::ListNode<T>* tmp = head;
        head = head->next;
        delete tmp;
    }
    mystl::ListNode<T>* current = head;
    while (current && current->next) 
    {
        if (current->next->val == value) 
        {
            mystl::ListNode<T>* tmp = current->next;
            current->next = current->next->next;
            delete tmp;
        } 
        else 
        {
            current = current->next;
        }
    }
}

template<typename T>
void mystl::ForwardList<T>::removeIf(bool (*pred)(const T&)) 
{
    while (head && pred(head->val)) 
    {
        mystl::ListNode<T>* tmp = head;
        head = head->next;
        delete tmp;
    }
    mystl::ListNode<T>* current = head;
    while (current && current->next) 
    {
        if (pred(current->next->val)) 
        {
            mystl::ListNode<T>* tmp = current->next;
            current->next = current->next->next;
            delete tmp;
        } 
        else 
        {
            current = current->next;
        }
    }
}

template<typename T>
void mystl::ForwardList<T>::push_back(const T& val)
{
    mystl::ListNode<T>* ptr = new mystl::ListNode<T>(val);
    if(head == nullptr)
    {
        head = ptr;
    }
    else
    {
        mystl::ListNode<T>* tmp = head;
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
        mystl::ListNode<T>* tmp = head;
        mystl::ListNode<T>* tmp1 = nullptr;
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
    mystl::ListNode<T>* ptr = new mystl::ListNode<T>(val);
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
        mystl::ListNode<T>* tmp = head;
        head = head -> next;
        delete tmp;
    }
}

template<typename T>
void mystl::ForwardList<T>::print() const
{
    mystl::Vector<mystl::ListNode<T>*> printed;
    mystl::ListNode<T>* tmp = head;
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
    mystl::ListNode<T>* ptr = nullptr;
    mystl::ListNode<T>* tmp = head;
    mystl::ListNode<T>* tmp1 = nullptr;
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
    mystl::ListNode<T>* ptr1 = head;
    mystl::ListNode<T>* ptr2 = head;
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
    mystl::ListNode<T>* tmp = head;
    mystl::ListNode<T>* tmp1 = nullptr;
    while(tmp != nullptr)
    {
        mystl::ListNode<T>* tmp2 = tmp -> next; 
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
    mystl::ListNode<T>* tmp1 = head;
    mystl::ListNode<T>* tmp2 = head;
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