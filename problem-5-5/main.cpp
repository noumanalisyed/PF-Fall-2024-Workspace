#include <iostream>
using namespace std;
int main() {
    int size = 0, no = 0 , sum =0;

    cin>>size;

    for(int i = 1; i <= size ; i++){
        cin>>no;
        sum = sum + no;
    }
    cout<<"Sum is : "<<sum<<endl;

    return 0;
}
