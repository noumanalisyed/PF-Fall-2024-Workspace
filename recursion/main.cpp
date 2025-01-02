#include <iostream>
using namespace std;

int factorial(int x);

int main() {
    int a = 5,  b = 0;
    b = factorial(a);
    cout<<a<<"!  = "<<b<<endl;
    return 0;
}
int factorial(int x){

    if(x == 1){
        cout<<"x = "<<x<<" * factorial("<<x-1<<")"<<endl;
        return 1;
    }
    else{
        cout<<"x = "<<x<<" * factorial("<<x-1<<")"<<endl;
        return x * factorial(x - 1);
    }

}