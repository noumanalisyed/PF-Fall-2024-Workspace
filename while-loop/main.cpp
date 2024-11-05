#include <iostream>
using namespace std;
int main() {
    int tableNo;
    int initialLimit, finalLimit;
    cout<<"Enter Table No : ";
    cin>>tableNo;
    cout<<"Enter Initial Limit : ";
    cin>>initialLimit;
    cout<<"Enter Final Limit : ";
    cin>>finalLimit;

    int i = initialLimit; // initialization

    while ( i <= finalLimit ){ // test expression
        cout<<tableNo<<" X "<<i<<" = "<<tableNo * i <<endl;
        i++;  // increment/decrement
    }
    return 0;
}
