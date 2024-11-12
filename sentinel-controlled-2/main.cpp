#include <iostream>
using namespace std;

int main() {
    int inputData , smallest, greatest;
    cout<<"Enter the data  (-1 to end) ";
    cin>>inputData;
    smallest = inputData;
    greatest = inputData;
    for (; inputData != -1; ) {
        if(smallest > inputData)
        {
            smallest = inputData;
        }
        if(greatest < inputData)
        {
            greatest = inputData;
        }
        cout<<"Enter the data (-1 to end) ";
        cin>>inputData;
    }
    cout<<"Smallest is : "<<smallest<<endl;
    cout<<"Greatest is : "<<greatest<<endl;
    return 0;
}

