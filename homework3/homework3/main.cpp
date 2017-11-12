//
//  main.cpp
//  homework3
//
//  Created by Alchemist on 2017/11/7.
//  Copyright © 2017年 Ry Shen. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class List;

class People {
protected:
    string name;
    int age;
    string sex;
    
public:
    People(string n, int a, string s) {
        name = n;
        age = a;
        sex = s;
    }
    ~People() {
        cout<< "People desturcted" << endl;
    }
    friend class List;
    void setData(string n, int a, string s) {
        name = n;
        age = a;
        sex = s;
    }
    void getData() {
        cout<< "People name:" << name << " age:" << age << " sex:" << sex << endl;
    }
};

class Teacher: public People {
    string teacherID;
    string title;
    
public:
    Teacher(string n, int a, string s, string id, string t) : People(n, a, s) {
        teacherID = id;
        title = t;
    }
    
    ~Teacher () {
        cout<< "Teacher desturcted" << endl;
    }
    void setData(string n, int a, string s, string id, string t) {
        name = n;
        age = a;
        sex = s;
        teacherID = id;
        title = t;
    }
    
    void getData() {
        cout<< "Teacher name:" << name << " age:" << age << " sex:" << sex <<  " teacherID: "<< teacherID << " title: " << title << endl;
    }
};

class Student: public People {
    string studentID;
    string major;
    
public:
    Student(string n, int a, string s, string id, string m) : People(n, a, s) {
        studentID = id;
        major = m;
    }
    
    ~Student () {
        cout<< "Student desturcted" << endl;
    }
    
    void setData(string n, int a, string s, string id, string m) {
        name = n;
        age = a;
        sex = s;
        studentID = id;
        major = m;
    }
    
    void getData() {
        cout<< "Student name:" << name << " age:" << age << " sex:" << sex <<  " studentID: "<< studentID << " major: " << major << endl;
    }
};

struct Node {
    People* peoptr;
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
            p->peoptr = q->peoptr;
            q = q->next;
        }
    }
    
    void addPeople (People peo){
        Node* p = new Node;
        p->peoptr = &peo;
        p->next = tail->next;
        tail->next = p;
        tail = tail->next;
        
    }
    
    void printList() {
        Node* p = head->next;
        
        while (p != nullptr) {
            cout<<p->peoptr->name<<endl;
            p = p->next;
        }
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
};





int main(int argc, const char * argv[]) {
    Teacher t("王老师",30,"女","001", "教授");
    Student s("大彪",18,"女","0001","软件技术");
    
    t.getData();
    s.getData();
    
    s.setData("大彪",18,"女","0002","软件技术");
     s.getData();
    
    List l;
    l.addPeople(t);
    l.addPeople(s);
    
    l.printList();
}
