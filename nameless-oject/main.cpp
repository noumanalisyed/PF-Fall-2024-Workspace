#include <iostream>
using namespace std;
int main() {

    int * ptr;
    ptr  = new int;

    cout<<"Enter Value";
    cin>>*ptr;

    cout<<"You have enetered a value = "<<*ptr<<endl;
    cout<<"You have enetered a value at address = "<<ptr<<endl;
    cout<<"You have enetered  at pointer = "<<&ptr<<endl;
    return 0;
}
