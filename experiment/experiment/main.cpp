//
//  main.cpp
//  experiment
//
//  Created by Alchemist on 2017/12/11.
//  Copyright © 2017年 Ry Shen. All rights reserved.
//

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class List;

class Quadrangle {
    protected:
    string name;
    friend class List;
    
    friend void  checkAnswer(const Quadrangle& quad);
    
    public:
    virtual double  area() = 0;
    virtual void draw() = 0;
    virtual string what() {
        return name;
    };
    virtual ~Quadrangle() {
        cout << "Quadrangle destructed..."<< endl;
    }
};

class Parallelogram: public Quadrangle {
    //在每种平行四边形形体中用宽高两种度量方式度量
    protected:
    int width, height;
    
    public:
    Parallelogram(string s, int w, int h) {
        name = s;
        width = w;
        height = h;
    }
    virtual int Width() {
        return width;
    }
    virtual int Height() {
        return height;
    }
    double  area() {
        return width * height;
    }
    void draw() {
        cout << name << " width = " << Width() << " height = " << Height() << endl;
    }
    virtual ~Parallelogram() {
        cout << name << " destructed.." << endl;
    }
};


class Rect: public Parallelogram {
    public:
    Rect(string s, int w, int h) : Parallelogram(s, w,  h) {
    }
    int Width() {
        return width;
    }
    int Height() {
        return height;
    }
    double  area() {
        return width * height;
    }
    void draw() {
        cout  << name << " : width = " << width << " height = " << height << endl;
    }
    virtual ~Rect() {
        cout << name << " destructed.." << endl;
    }
};

class Diamond: public Parallelogram {
    public:
    Diamond(string s, int w, int h) : Parallelogram(s, w,  h) {
    }
    int Width() {
        return width;
    }
    int Height() {
        return height;
    }
    double  area() {
        return width * height;
    }
    void draw() {
        cout  << name << " : diagonal width = " << width << " diagonal height = " << height << endl;
    }
    virtual ~Diamond() {
        cout << name << " destructed.." << endl;
    }
};

class Square: public Parallelogram {
    public:
    Square(string s, int w, int h) : Parallelogram(s, w,  w) {
    }
    int Width() {
        return width;
    }
    int Height() {
        return height;
    }
    double  area() {
        return width * height;
    }
    void draw() {
        cout  << name << " : side length = " << width << endl;
    }
    virtual ~Square() {
        cout << name << " destructed.." << endl;
    }
};

class Trapezoid: public Quadrangle {
    protected:
    int width, height, width2;
    
    public:
    Trapezoid(string s, int w, int h, int w2) {
        name = s;
        width = w;
        height = h;
        width2 = w2;
    }
    virtual int Width() {
        return width;
    }
    virtual int Height() {
        return height;
    }
    virtual int Width2() {
        return width2;
    }
    double  area() {
        return (width+width2) * height / 2;
    }
    void draw() {
        cout  << name << " : width = " << width << " height = " << height << " width2 = " << width2 << endl;
    }
    virtual ~Trapezoid() {
        cout << name << " destructed.." << endl;
    }
};

void showDetail(Quadrangle* quad) {
    cout << "name : " << (*quad).what() << endl;
    (*quad).draw();
    cout << "area : " << (*quad).area() << endl;
}





class List {
    
    struct Node {
        Quadrangle* quadptr;
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
    void  push_back(Quadrangle& quad){
        Node* p = new Node;
        p->quadptr = &quad;
        p->next = tail->next;
        tail->next = p;
        tail = tail->next;
        len++;
    }
    typedef void (*ACCESSFUN)(Quadrangle *);
    void  traverset(ACCESSFUN showDetail) {
        Node* p = head->next;
        
        while (p != nullptr) {
            showDetail(p->quadptr);
             cout << "--------------------" << endl;
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
        showDetail(p->quadptr);
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
};


void  getAnswer( Quadrangle& quad) {
    cout<<"输入其面积计算结果： ";
    for(;;)
    {
        double answer=0.0;
        cin>>answer;
        if( answer != quad.area())
            cout<<"结果错误，请重新计算： ";
        else
        {
            cout<<" 结果正确"<<endl;
            break;
        }
    }
}

//
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    List list;
//    int stop = 0;
//    srand(unsigned(time(NULL)));
//    cout<<"学习四边形"<<endl;
//   
//    while (stop != 1) {
//        Quadrangle *quad;
//        switch (rand() % 5) {
//            case 0:
//                quad = new Parallelogram("Parallelogram", (rand() % 9) + 1,(rand() % 9) + 1);
//                break;
//            case 1:
//                quad = new Rect("Rectangle", (rand() % 9) + 1,(rand() % 9) + 1);
//                break;
//            case 2:
//                quad = new Diamond("Diamond", (rand() % 9) + 1,(rand() % 9) + 1);
//                break;
//            case 3:
//                quad = new Square("Square",(rand() % 9) + 1,(rand() % 9) + 1);
//                break;
//            default:
//                 quad = new Trapezoid("Trapezoid",(rand() % 9) + 1,(rand() % 9) + 1, (rand() % 9) + 1);
//                break;
//        }
//        quad->draw();
//        list.push_back(*quad);
//        getAnswer(*quad);
//        
//        cout<<"继续学习还是复习？（继续学习的话请输入0，如果是想要复习的话请输入1）: "<<endl;
//        cin >> stop;
//    }
//    
//    cout << "复习四边形学习：" << endl;
//    list.traverset(showDetail);
//
//    return 0;
//}
//
//
//
//
//
//
//
//
//
