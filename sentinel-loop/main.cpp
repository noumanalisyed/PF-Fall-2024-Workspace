#include <iostream>
using namespace std;

int main() {
    int inputData , count, smallest, greatest;
    cout<<"Enter the count ";
    cin>>count;
    cout<<"Enter the data ";
    cin>>inputData;
    smallest = inputData;
    greatest = inputData;
    for (int i = 1; i < count; ++i) {
        if(smallest > inputData)
        {
            smallest = inputData;
        }
        if(greatest < inputData)
        {
            greatest = inputData;
        }
        cout<<"Enter the data ";
        cin>>inputData;
    }
    cout<<"Smallest is : "<<smallest<<endl;
    cout<<"Greatest is : "<<greatest<<endl;
    return 0;
}
