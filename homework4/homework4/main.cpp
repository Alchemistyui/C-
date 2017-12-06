//
//  main.cpp
//  homework4
//
//  Created by Alchemist on 2017/11/30.
//  Copyright © 2017年 Ry Shen. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

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
    virtual ~People() {
        cout<< "People desturcted" << endl;
    }

   virtual  void setData(string n, int a, string s) {
        name = n;
        age = a;
        sex = s;
    }
   virtual  void getData() {
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
    void setData(string n, int a, string s) {
        name = n;
        age = a;
        sex = s;
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


int main(int argc, const char * argv[]) {
    Student stu("大彪",18,"女","0001","软件技术");
    People& s = stu;
    
    Teacher teacher("王老师",30,"女","001", "教授");
    People& t = teacher;
    s.getData();
    s.setData("大彪",18,"男");
    s.getData();
    
    t.getData();
    
}
