#include <iostream>
using namespace std;

int hcf(int x,int y);
int main() {
    int no1 = 24, no2 = 16, result = 0;
    result = hcf(no1,no2);
    cout<<"No1 = "<<no1<<" , No2 = "<<no2<<" HCF = "<<result<<endl;
    return 0;
}
int hcf(int x,int y){
    if( y == 0){
        return x;
    }
    else{
        return hcf(y, x % y);
    }
}