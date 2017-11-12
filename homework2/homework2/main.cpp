//
//  main.cpp
//  homework2
//
//  Created by Alchemist on 2017/10/21.
//  Copyright © 2017年 Ry Shen. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class List;

class Employee {
    
    string name;
    int salary;
    static int salarySum;
    
public:
    Employee() {
        name = "";
        salary = 0;
    }
    Employee(string n, int s) {
        name = n;
    salary = s;
        salarySum += s;
    }
void showName() {
        
    cout<<"name:"<< name<< endl;
}
    void showSalary() {
        cout<< salary<< endl;
    }
    
    static void showSum (){
        cout << salarySum << endl;
    }
    friend int maxSalary(const List& l);
    friend class List;
    ~Employee () {
        name = "";
        salary = 0;
    }
};

int Employee::salarySum = 0;


struct Node {
    Employee e;
    Node* next;
};


class List {
    Node* head, *tail;
    size_t len;
    
public:
    //List为带头结点的链表
    List () {
        head = new Node;
        head->next = nullptr;
        tail = head;
        len = 0;
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
            p->e = q->e;
            q = q->next;
        }
    }
    
    void addEmployee (Employee emp){
        Node* p = new Node;
        p->e = emp;
        p->next = tail->next;
        tail->next = p;
        tail = tail->next;
        
    }
    
    void printList() {
        Node* p = head->next;
       
        while (p != nullptr) {
            cout<<p->e.name<< ":"<< p->e.salary<<endl;
            p = p->next;
        }
    }
    
    friend int maxSalary(const List& l);
    ~List() {
        Node* p;
        while(head!=tail)
        {
            p=head;
            head = head->next;
            delete p;
        }
        tail = nullptr;
    }
};

int maxSalary(const List& l) {
    int max = 0;
    Node* p = l.head->next;
    
    while(p != nullptr) {
        if(max < (p->e.salary)) {
            max = p->e.salary;
            p = p->next;
        }
    }
    return max;
}

int main(int argc, const char * argv[]) {
    
    Employee person1("张三",100), person2("李四",200);
    person1.showSalary();
    
    person2.showSalary();
    Employee::showSum();
    
    List l;
    l.addEmployee(person1);
    l.addEmployee(person2);

    l.printList();
    cout<<"max salary: "<< maxSalary(l)<< endl;
    l.~List();
    return 0;
}
