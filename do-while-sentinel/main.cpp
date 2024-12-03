#include <iostream>
using namespace std;
int main() {

    int number {0};
    int sum {0};
    cout<<"7 -- Enter the positive number (-1 to end)\n8 -- :";
    cin>>number;

    /*do{
        sum = sum + number;
        cout<<"Enter the positive number (-1 to end)";
        cin>>number;
    }while(number != -1);*/

    for(; number != -1;){
        sum = sum + number;
        cout<<"18 -- Enter the positive number (-1 to end)\n 19 -- : ";
        cin>>number;
    }
    /*while(number != -1){
        sum = sum + number;
        cout<<"Enter the positive number (-1 to end)";
        cin>>number;
    }*/
    cout<<"Sum is : "<<sum<<endl;
    return 0;
}
