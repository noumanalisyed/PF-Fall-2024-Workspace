#include <iostream>
using namespace std;

int add(int &, int &);

int main() {
    int a = 7, b = 8, c = 0;
    cout<<"a = "<<a<<" ,  b = "<<b<<endl;

    c = add(a,b);
    cout<<a<<" + "<<b<<" = "<<c<<endl;

    return 0;
}
int add(int & x, int & y){
    x++;
    return x + y;
}
