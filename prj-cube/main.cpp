#include <iostream>
using namespace std;

int cube(int base);
float area(float length, float width);
int factorial(int number);
int main() {
    std::cout<<"Processor enters in main function "<<std::endl;
    int x = 6;
    int result = 0;
    float areaOfRectangle = 0;
    float lengthOfRectangle = 9.4;
    float widthOfRectangle = 9.4;
    result = cube(x);
    std::cout << x<<" ^3 = " <<result<< std::endl;
    areaOfRectangle = area(lengthOfRectangle,widthOfRectangle);
    std::cout << lengthOfRectangle<<" *  " <<widthOfRectangle<<" = "<<areaOfRectangle<< std::endl;
    //int resultFactorial = factorial(5);
    std::cout << "Factorial of 5 = " << factorial(5) << std::endl;
    std::cout<<"Processor leaves main function "<<std::endl;
    return 0;
}

int cube(int base){
    std::cout<<"Processor enters in cube function "<<std::endl;
    return base * base * base;
}
float area(float length, float width){
    std::cout<<"Processor enters in sarea function "<<std::endl;
    return length * width;
}
int factorial(int number){
    std::cout<<"Processor enters in factorial function "<<std::endl;
    int answer = 1;
    while (number >= 1){
        answer *= number;
        number--;
    }
    return answer;
}


