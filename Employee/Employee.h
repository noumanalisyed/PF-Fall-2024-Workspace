//
// Created by Syed Nouman Ali Shah on 03/12/2024.
//

#ifndef EMPLOYEE_EMPLOYEE_H
#define EMPLOYEE_EMPLOYEE_H
#include <iostream>

class Employee{
public:
    Employee();
    Employee(long id,std::string fName,
             std::string lName,std::string add,
             std::string jt,double sal);
    void display();

private:
    long empId {0};
    std::string firstName {""};
    std::string lastName {""};
    std::string address {""};
    std::string jobTitle {""};
    double salary {0.0f};
};



#endif //EMPLOYEE_EMPLOYEE_H
