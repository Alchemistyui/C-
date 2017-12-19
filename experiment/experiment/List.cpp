//
//  List.cpp
//  experiment
//
//  Created by Alchemist on 2017/12/18.
//  Copyright © 2017年 Ry Shen. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;


template <typename T>
class List {
    
    struct Node {
        T* quadptr;
        Node* next;
    };
    
    
    Node* head, *tail;
    int len;
    
    
public:
    //List为带头结点的链表
    List () {
        head = new Node;
        head->next = nullptr;
        tail = head;
        len = 0;
    }
    int   size(){
        return len;
    }
    List (const List& l) {
        Node* p, *q = l.head;
        
        len = l.len;
        //头结点占一个Node
        head = new Node;
        tail = head;
        
        for (size_t i = 0; i < len; i++) {
            p = new Node;
            p->next = nullptr;
            tail->next = p;
            p->quadptr = q->quadptr;
            q = q->next;
        }
    }
    void  push_back(T& quad){
        Node* p = new Node;
        p->quadptr = &quad;
        p->next = tail->next;
        tail->next = p;
        tail = tail->next;
        len++;
    }
    void  traverset() {
        Node* p = head->next;
        
        while (p != nullptr) {
            cout<<*(p->quadptr)<<endl;
            p = p->next;
        }
    }
    
    void  operator[](int index) {
        Node* p = head->next;
        int nowIndex = 0;
        
        while (nowIndex != index) {
            p = p->next;
            nowIndex++;
        }
        cout << "data : " << *(p->quadptr)<<endl;
    }
    
    void pop_back() {
        Node* p = head->next;
        
        while (p->next != tail) {
            p = p->next;
        }
        p->next = tail->next;
        delete tail;
        tail = p;
        len--;
    }
    ~List() {
        Node* p;
        while(head!=tail)
        {
            p=head;
            head = head->next;
            delete p;
        }
        tail = nullptr;
        
        cout<<"List destructed"<<endl;
    }
    
    
    class Iterator {
    private:
        Node* p;
        
    public:
        Iterator() {
            p = nullptr;
        }
        
        Iterator( const List& l) {
            p = (l.head)->next;
        }
        
        Iterator& operator++() {
            p = p->next;
            return *this;
        }
        
        bool operator!=(const Iterator& itr) {
            return itr.p != p;
        }
        
        T& operator*() {
            return *(p->quadptr);
        }
        
        Iterator& operator=(const Iterator& itr) {
            p = itr.p;
            return *this;
        }
        
        Iterator operator+(int i) {
            for(int j = 0; j < i; j++) {
                p = p->next;
            }
            return *this;
        }
    };
    
    Iterator begin() {
        return Iterator(*this);
    }
    
    Iterator end() {
        return Iterator();
    }
};


//int main(int argc, const char * argv[]) {
//    
//    List<int> list;
//    
//    int i = 1;
//    list.push_back(i);
//     int j = 2;
//     list.push_back(j);
//    int k = 3;
//    list.push_back(k);
//   
////    list.traverset();
//    
//    for (List<int>::Iterator itr = list.begin(); itr != list.end(); ++itr) {
//
//        cout << *itr << endl;
//    }
//   return 0;
//}









