#include <iostream>
using namespace std;

class Time{
    public:
    Time(){
        hour = min = sec = 0;
    }
    Time(int h,int m,int s){
        hour = (h >= 0 && h <= 24) ? h : 0;
        min = ( m >= 0 && m <= 60) ? m : 0;
        sec = ( s >= 0 && s <= 60) ? s : 0;
    }
    void display(){
        cout<<hour<<":"<<min<<":"<<sec<<endl;
    }
private:
    int hour;
    int min;
    int sec;
};
class Employee{
public:
    Employee(){
        id = 0;
        name = "";
    }
    Employee(int id,string name){
        Employee::id = id;
        Employee::name = name;
    }
    void printEmployee(){
        cout<<"Employee-- [Id : "<<id<<" , Name : "<<name<<"] \n";
    }
private:
    int id;
    string name;
};
int main() {
    Time t[3];
    Time t1;
    Time t2(12,24,36);
    Time t3(99,99,65);
    t[0] = t1;
    t[1] = t2;
    t[2] = t3;

    for(int i=0; i < 3; i++){
        t[i].display();
    }

    Employee empArray[3];
    Employee e1 (100,"Ahmad");
    Employee e2 (101,"Akmal");
    Employee e3 (102,"Asim");
    empArray[0] = e1;
    empArray[1] = e2;
    empArray[2] = e3;
    for(Employee em : empArray){
        em.printEmployee();
    }
    //t1.display();
    //t2.display();
    //t3.display();
    return 0;
}
