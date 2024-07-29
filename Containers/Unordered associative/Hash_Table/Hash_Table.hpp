#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include <vector>


namespace mystl
{
    template<typename T1 , typename T2>
    class SingleLinkedList
    {
        class Node
        {
            private:
                T1 key;
                T2 val;
                Node* next;
            public:
                Node();
                Node(const T1& , const T2&);
                ~Node();
            friend class SingleLinkedList;
        };
        private:
            Node* head;
        public:
            SingleLinkedList();
            void push_back(const T1& , const T2&);
            void pop_back();
            bool remove(const T1&);
            T2 find(const T1&) const;
            void print() const;
            ~SingleLinkedList();
    };
    template<typename T1 , typename T2>
    class HashMap
    {
        private:
            int count;
            int cap;
            SingleLinkedList<T1 , T2>* arr;
        private:
            int HashFunction(const T1&) const;
            bool isPrime(int) const;
            int nextPrime(int) const;
            void resize();
        public:
            HashMap();
            void insert(const T1& , const T2&);
            void remove(const T1&);
            T2 search(const T1&) const;
            ~HashMap();
    };
}

template<typename T1 , typename T2>
mystl::SingleLinkedList<T1 , T2>::Node::Node() : key(T1()) ,  val(T2()) , next(nullptr)
{

}

template<typename T1 , typename T2>
mystl::SingleLinkedList<T1 , T2>::Node::Node(const T1& key, const T2& val) : key(key) , val(val) , next(nullptr)
{

}

template<typename T1 , typename T2>
mystl::SingleLinkedList<T1 , T2>::Node::~Node()
{

}

template<typename T1 , typename T2>
mystl::SingleLinkedList<T1 , T2>::SingleLinkedList() : head(nullptr)
{

}

template<typename T1 , typename T2>
void mystl::SingleLinkedList<T1 , T2>::push_back(const T1& key, const T2& val) 
{
    Node* ptr = new Node(key , val);
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

template<typename T1 , typename T2>
void mystl::SingleLinkedList<T1 , T2>::pop_back()
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

template<typename T1, typename T2>
bool mystl::SingleLinkedList<T1, T2>::remove(const T1& key)
{
    Node* cur = head;
    Node* prev = nullptr;
    while (cur != nullptr)
    {
        if (cur -> key == key)
        {
            if (prev == nullptr)
            {
                head = cur->next;
            }
            else
            {
                prev->next = cur->next;
            }
            delete cur;
            return true;
        }
        prev = cur;
        cur = cur->next;
    }
    std::cout << "Key not found" << std::endl;
    return false;
}

template<typename T1, typename T2>
T2 mystl::SingleLinkedList<T1, T2>::find(const T1& key) const
{
    Node* cur = head;
    while (cur != nullptr)
    {
        if (cur -> key == key)
        {
            return cur -> val;
        }
        cur = cur->next;
    }
    std::cout << "Key not found" << std::endl;
    return T2();
}

template<typename T1 , typename T2>
void mystl::SingleLinkedList<T1 , T2>::print() const
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

template<typename T1 , typename T2>
mystl::SingleLinkedList<T1 , T2>::~SingleLinkedList()
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

template<typename T1 , typename T2>
mystl::HashMap<T1 , T2>::HashMap() : count(0) , cap(31) , arr(new SingleLinkedList<T1 , T2>[31])
{
                
}

template<typename T1 , typename T2>
int mystl::HashMap<T1 , T2>::HashFunction(const T1& key) const
{   
    return std::hash<T1>()(key) % cap;            
}

template<typename T1 , typename T2>
bool mystl::HashMap<T1 , T2>::isPrime(int num) const
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
            return true;
        }
    }
    return false;
}

template<typename T1 , typename T2>
int mystl::HashMap<T1 , T2>::nextPrime(int num) const
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

template<typename T1 , typename T2>
void mystl::HashMap<T1 , T2>::resize()
{
    int tmpCap = nextPrime(cap);
    SingleLinkedList<T1 , T2>* tmpArr = new SingleLinkedList<T1 , T2>[tmpCap];
    for(int i = 0 ; i < cap ; i++)
    {
        tmpArr[i] = arr[i];
    }
    delete[] arr;
    arr = tmpArr;
    cap = tmpCap;
}

template<typename T1 , typename T2>
void mystl::HashMap<T1 , T2>::insert(const T1& key , const T2& val)
{
    int ind = HashFunction(key);
    arr[ind].push_back(key , val);
    count++;
    if(count > 4*cap)
    {
        resize();
    }
}

template<typename T1 , typename T2>
void mystl::HashMap<T1 , T2>::remove(const T1& key)
{
    int ind = HashFunction(key);
    bool check = arr[ind].remove(key);
    if(check)
    {
        count--;
    }
}

template<typename T1, typename T2>
T2 mystl::HashMap<T1, T2>::search(const T1& key) const
{
    int ind = HashFunction(key);
    return arr[ind].find(key);
}

template<typename T1, typename T2>
mystl::HashMap<T1, T2>::~HashMap()
{
    delete[] arr;
    cap = 0;
}
#endif //HASH_TABLE_H