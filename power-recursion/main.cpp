#include <iostream>
using namespace std;

int power(int base, int exp);
int main() {
    int base = 2, exp = 3;
    int result = power(base,exp);
    cout<<result;
    return 0;
}

int power(int base, int exp){
    if( exp == 0){
        return 1;
    }
    else{
        return base * power(base , exp-1);
    }
}