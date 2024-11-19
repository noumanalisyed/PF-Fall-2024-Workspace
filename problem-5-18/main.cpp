#include <iostream>
using namespace std;
int main() {
    int ten = 1, no = 145, base = 2;
    int remainder = 0, quotient = 0, equivalent = 0;

    cout<<"Enter Decimal No : ";
    cin>>no;

    int temp = no;
    char ch;
    string strMessage = "";
    cout<<"Enter the Conversion Decimal to Binary/Octal (b/o) "<<endl;
    cin>>ch;
    switch (ch) {
        case 'B':
        case 'b':
            base = 2;
            strMessage = " Binary Equivalent  : ";
            break;
        case 'O':
        case 'o':
            base = 8;
            strMessage = " Octal Equivalent  : ";
            break;
    }
    /*if(ch == 'b'){
        base = 2;
        strMessage = " Binary Equivalent  : ";
    }
    else if(ch == 'o'){
        base = 8;
        strMessage = " Octal Equivalent  : ";
    }*/
    cout<<"Decimal "<<no<<" --> ";
    int i = 1;
    while ( temp != 0){
        remainder = temp % base;
       // cout<<"bin remainder = "<<binRemainder<<endl;
        quotient = temp / base;
        //cout<<"bin quotient = "<<binQuotient<<endl;
        temp = quotient;
        //cout<<"temp = "<<temp<<endl;
        equivalent = equivalent + remainder * ten;
        ten = ten * 10;
    }
    cout<<strMessage<<equivalent<<endl;
    return 0;
}
