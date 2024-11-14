#include <iostream>
using namespace std;
int main() {
    int no1,no2, result = 0;

    cout << "Enter No1 : ";
    cin>>no1;
    cout << "Enter No2 : ";
    cin>>no2;

    for (int i = 1; i <= no2; ++i) {
        result = result + no1;
    }
    cout<<no1<<" x "<<no2<<" = "<<result<<endl;
    return 0;
}
