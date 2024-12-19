#include <iostream>
using namespace std;
float square(float x);
float hypotenuse(float base, float prep);
int main() {
    float base = 0, prep = 0, hyp = 0;
    cout<<"Enter the base of the triangle : ";
    cin>>base;
    cout<<"Enter the perpendicular of the triangle : ";
    cin>>prep;

    hyp = hypotenuse(base,prep);
    cout<<"Base = "<<base<<" , Prependicular = "<<prep<<" , Hypotenuse = "<<hyp<<endl;

    return 0;
}
float hypotenuse(float base, float prep){
    return sqrt(square(base) + square(prep));
}
float square(float x){
    return x * x;
}