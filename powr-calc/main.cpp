#include <iostream>
using namespace std;
int main() {
    int exponent = 0;
    int base = 0;
    int power = 1;
    int i = 0;

    cout << "Enter the Base value  :";
    cin>>base;
    cout << "Enter the Exponent value  :";
    cin>>exponent;
    i = 1;
    while(i <= exponent){
        power = power * base;
        i++;
    }
    cout<<base<<" ^ "<<exponent<<" = "<<power<<endl;
    return 0;
}
