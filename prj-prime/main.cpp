#include <iostream>
using namespace std;

bool isPrime(int num) {
    int count = 0;
    for (int divisor = 2; divisor <= num/2;  divisor++) {
        if(num % divisor == 0){
            count ++;
        }
    }
    if(count > 0)
        return false;
    else
        return true;
}

int main(){
    int p;
    cout << "Enter a numer: ";
    cin >> p;
    bool status = isPrime(p);

    if (status == false){
        cout << p <<" is not a Prime "<<endl;
    }
    else {
        cout <<p<< " is a Prime "<<endl;
    }
}
