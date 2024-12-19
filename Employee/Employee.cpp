//
// Created by Syed Nouman Ali Shah on 03/12/2024.
//

#include "Employee.h"

Employee::Employee(){

}
Employee::Employee(long id,std::string fName,
         std::string lName,std::string add,
         std::string jt,double sal):empId(id),firstName(fName),lastName(lName)
        ,address(add),jobTitle(jt),salary(sal){

}
void Employee::display(){
    std::cout<<"Employee -- Information "<<std::endl;
    std::cout<<"First Name : "<<firstName<<std::endl;
    std::cout<<"Last Name : "<<lastName<<std::endl;
    std::cout<<"Address : "<<address<<std::endl;
    std::cout<<"Job Title : "<<jobTitle<<std::endl;
    std::cout<<"Salary : "<<salary<<std::endl;

}
