//
//  main.cpp
//  no.1
//
//  Created by Alchemist on 2017/9/24.
//  Copyright © 2017年 Ry Shen. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class employee {
  
    string name;
    int salary;
    static int salarySum;
    
public:
    
    void salaryNum (int num) {
        salary = num;
    }
    
    static int addSalary (const employee &e) {
        return salarySum += e.salary;
    }
    
    static void showSum (){
        cout << salarySum << endl;
        
    }
};

int employee::salarySum = 0;

int main(int argc, const char * argv[]) {
   
    employee person1, person2;
    person1.salaryNum(10);
    person1.addSalary(person1);
    person1.showSum();
    
    person2.salaryNum(20);
    person1.addSalary(person2);
    person2.showSum();
    
    return 0;
}
