#include <iostream>
using namespace std;
// returnValueType functionName (ParameterList seprated by commas);
int sum(int x,int y);
int sub(int x,int y);
int square(int x);
int cube(int x);
int main() {
    int a = 4, b = 6 , c = 0;
    c = sum(a,b);// function call
    cout<<a<<" + "<<b<<" = "<<c<<endl;
    c = sub(a,b);// function call
    cout<<a<<" - "<<b<<" = "<<c<<endl;
    cout<<a<<"^ 2 = "<<square(a)<<endl;
    cout<<a<<"^ 3 ="<<cube(a)<<endl;
    return 0;
}
int sum(int x,int y){
    return x + y;
}
int sub(int x,int y){
    return x - y;
}

int square(int x){
    return x * x;
}
int cube(int x){
    return x*x*x;
}