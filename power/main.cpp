#include <iostream>
using namespace std;
int power(int base,int expo) {
    int result = 1;
    for (int i = 1; i <= expo; i++) {
        result *= base;
    }
    return result;
}
int main() {
    int base,expo;
    cout<<"enter base ";
    cin>>base;
    cout<<"Enter expo";
    cin>>expo;
    cout<<"power"<<power(base,expo);
    return 0;
}
