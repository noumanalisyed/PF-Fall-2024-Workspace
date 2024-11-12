#include <iostream>
using namespace std;
int main() {
    int number , factorial = 1;

    cout<<"Enter the Number :";
    cin>>number;
    for (int i = number; i >= 1; --i) {
        factorial = i * factorial;
    }
    cout<<number<<"! is : "<<factorial<<endl;
    return 0;
}
