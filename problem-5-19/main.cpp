#include <iostream>
using namespace std;
int main() {
    float number = 4;
    float generatedNo = 1;
    float piValue = 0;
    for (int i = 1; i < 100000; ++i, generatedNo += 2) {
        if(i % 2 == 1){
            piValue = piValue + number / generatedNo;
        }
        else{
            piValue =  piValue - number / generatedNo;
        }
    }
    cout<<"PI = "<<piValue <<endl;
    return 0;
}
