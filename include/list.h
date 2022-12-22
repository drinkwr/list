#ifndef LIST
#define LIST


#include <ctime>
#include <iostream>

template <class T>
struct Node {
    T element;
    Node * next;
    Node(T el)
    {
        element=el;
        next=nullptr;
    }
};


template <class T>
class Forward_List
{
    /*struct Node {
        T element;
        Node * next = nullptr;
        Node(T, next = nullptr);
    };*/
    Node<T> * first;

private:
    Forward_List & shift_1_elem()
    {
        Node<T> * tmp = first;
        Node<T> * prev = nullptr;
       while(tmp->next != nullptr)
       {
           prev = tmp;
           tmp = tmp->next;
       }
        tmp->next = first;
        prev->next = nullptr;
        first = tmp;
        return * this;
    }

public:
    //template <class T>
    Forward_List()
    {
        first = nullptr;
    }
    
    Forward_List(int n, T value)
    {
        if(n<0)
            throw "inncorrect elem count";
        first = new Node<T>(value);
        if(n ==0 )return;
        Node<T> * tmp = first;
        for(int i = 1; i < n; i++)
        {
            tmp->next = new Node<T>(value);
            tmp = tmp->next;
        }
    }
    bool emty()
    {
        return first == nullptr;
    }
    
    size_t size()
    {
        Node<T> * tmp = first;
        int n = 0;
        while(tmp)
        {
            n++;
            tmp = tmp->next;
        }
        return n;
    }
    void clear()
    {
        Node<T> * tmp = first;
        while(tmp)
        {
            Node<T> * tmp2 = tmp->next;
            delete tmp;
            tmp = tmp2;
        }
        first = nullptr;
    }
    ~Forward_List()
    {
        clear();
    }
    
    Forward_List(Forward_List & list)
    {
        first = nullptr;
        Node<T> * tmp = list.first;
        while(tmp)
        {
            push_Back(tmp->element);
            tmp = tmp->next;
        }
    }
    
    Forward_List(const Forward_List & list)
    {
        Node<T> * listPtr = list.first;
        if(!listPtr)return;
        first = new Node<T> (listPtr->element);
        listPtr = listPtr->next;
        Node<T> * tmp = first;
        while(listPtr)
        {
            tmp->next = new Node<T>(listPtr->element);
            listPtr = listPtr->next;
            tmp = tmp->next;
        }
    }
    
    void insert_after (Node<T> * prev, T v)
    {
        Node<T> * tmp = new Node<T> (v);
        tmp->next = prev->next;
        prev->next = tmp;
    }
    
    void push_Front (T v)
    {
        Node<T> * tmp = new Node<T>(v);
        tmp->next = first;
        first = tmp;
    }
    
    void delete_after (Node<T> * prev)
    {
        if (!prev->next) throw(1);
        Node<T> * tmp = prev->next;
        prev->next = prev->next->next;
        delete tmp;
    }
    void delete_Front ()
    {
        if(first==0) throw(1);
        Node<T> * tmp = first->next;
        delete first;
        first = tmp;
    }
    void push_Back(T v)
    {
        if(first == nullptr)
        {
            first = new Node<T> (v);
            return;
        }
        Node<T> * tmp;
        for(tmp = first; tmp->next; tmp=tmp->next)
        {}
        tmp->next = new Node<T>(v);
    }
    T pop_front()
    {
        return first->element;
    }
    Forward_List & operator = (Forward_List & list)
    {
        if(&list == this)
        {
            return * this;
        }
        Node<T> * listPtr = list.first;
        if(!listPtr)
            return * this;
        first = new Node<T> (listPtr->element);
        listPtr = listPtr->next;
        Node<T> * tmp = first;
        while(listPtr)
        {
            tmp->next = new Node<T>(listPtr->element);
            listPtr = listPtr->next;
            tmp = tmp->next;
        }
        return * this;
    }
    
   friend std::ostream & operator << (std::ostream & out, Forward_List & list)
    {
       Node<T> * tmp = list.first;
       while(tmp)
       {
           out << tmp->element <<' ';
           tmp = tmp->next;
       }
       out << "\n";
       return out;
    }
    
    bool empty()
    {
        return first == nullptr;
    }
    Node<T> * find(T elem)
    {
        Node<T> * tmp = first;
        while(tmp)
        {
            if(tmp->element == elem)
                return tmp;
            tmp = tmp->next;
        }
        return nullptr;
    }
    
    Forward_List & shift_k_elem(int k)    //задача №6
    {
        if(first == nullptr)
        {
            return * this;
        }
        
        if(first->next == nullptr)
        {
            return * this;
        }
        
        if(k<0)
        {
            throw "K can not be negative";
        }
        
        if(k == 0)
        {
            return * this;
        }
        while(k--)
        {
            shift_1_elem();
        }
        return * this;
    }
};

#endif
