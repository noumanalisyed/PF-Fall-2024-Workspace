#include <iostream>
using namespace std;
int main() {
    int no , noOfTerms = 0 ;
    float average = 0.0 , sum;
    cout<<"Enter the no ";
    cin>>no;
    while(no != 9999){
        sum = sum + no;
        noOfTerms++;
        cout<<"Enter the no ";
        cin>>no;
    }
    average =  sum / noOfTerms;

    cout<<"Total Entered numbers are : "<<noOfTerms<<endl;
    cout<<"Sum is : "<<sum<<endl;
    cout<<"Average is : "<<average<<endl;



    return 0;
}
