#include <iostream>
using namespace std;
float calculateCharges(float hours);

int main() {
    int carNo;
    float noOfHours;
    float charges = 0.0f;
    cout<<"Car No \t Hours \t Charges \n";
    int i = 1;
    while (i <= 3) {
        cout << "Enter the Car No : ";
        cin >> carNo;
        cout << "Enter No of Hours car stay in parking : ";
        cin >> noOfHours;
        charges = calculateCharges(noOfHours);
        cout<<carNo<<"\t"<<noOfHours<<"\t"<<charges<<" \n";
        i++;
    }
    return 0;
}
float calculateCharges(float hours){
    float charges = 2;
    if(hours == 24){
        return 10;
    }
    else if(hours <= 3){
        return charges;
    }
    else if(hours > 3 && hours < 24){
        int time = hours - 3;
        charges = charges + time * 0.5;
    }
    return charges;
}
