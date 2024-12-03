#include <iostream>
using namespace std;
int main() {
    int number = 1;
    do{
        cout<<"Enter Number between 1 to 10 ";
        cin>>number;
        if(number  < 1 || number > 10){
            cout<<"Invalid number!! , please try again"<<endl;
        }
    }while(number  < 1 || number > 10);
    std::cout << "Number is  "<<number << std::endl;
    return 0;
}
