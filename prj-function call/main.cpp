#include <iostream>
using namespace std;

void f1();
void f2();
int add(int x,int y);
int sub(int x,int y);

int main() {
    cout<<"Activation Record -- Created On Entering in main -- function "<<endl;
    for (int i = 1; i <= 5; i++) {
        f1();
    }
    //f1(); // call of f1 and activation record created
    int a = 4,  b = 3 , c= 0;
    c = add(a,b);
    cout<<a<<" + "<<b<<" = "<<c<<endl;
    c = sub(a,b);
    cout<<a<<" - "<<b<<" = "<<c<<endl;
    cout<<"Activation Record -- Destroyed On leaving from main -- function "<<endl;
    return 0;
}
int add(int x,int y){
    cout<<"Activation Record -- Created On Entering in add -- function "<<endl;
    cout<<"Activation Record -- Destroyed On leaving from add -- function "<<endl;
    return x  + y;
}
int sub(int x,int y){
    cout<<"Activation Record -- Created On Entering in sub -- function "<<endl;
    cout<<"Activation Record -- Destroyed On leaving from sub -- function "<<endl;
    return x  - y;
}
void f1(){
    cout<<"Activation Record -- Created On Entering in f1 -- function "<<endl;
    f2();
    cout<<"f1-- blah\n f1.. blah\n f1... blah\n";
    cout<<"Activation Record -- Destroyed On leaving from f1 -- function "<<endl;
}
void f2(){
    cout<<"Activation Record -- Created On Entering in f2 -- function "<<endl;
    cout<<"f2 .. blah\n f2 .. blah\n f2 ... blah\n";
    cout<<"Activation Record -- Destroyed On leaving from f2 -- function "<<endl;
}