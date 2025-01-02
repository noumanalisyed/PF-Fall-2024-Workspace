#include <iostream>
using namespace std;
float inputSales();
float calculateCommision(float sales, float percentage);
float calculateSalary(float weeklySalary, float commission);
void displayDetails(float commision, float sales, float percentage, float weeklySalary);
void calculateSalaryRange(int salary,int salaryData[],int s);
void displaySalaryRanges(int salaries[],int s);

int main() {
    int salaries[9] = {0};
    float sales, percentage = 9, commission, weeklySalary = 200, salary;
    int employeeSize = 5;
    for (int i = 0; i < employeeSize; ++i) {

        sales = inputSales();

        commission = calculateCommision(sales, percentage);
        salary = calculateSalary(weeklySalary, commission);
        displayDetails(commission, sales, percentage, weeklySalary);

        calculateSalaryRange(salary, salaries, 9);
    }
    displaySalaryRanges(salaries, 9);
    return 0;
}
float inputSales(){
    float sales;
    cout<<"Enter the sales person sales ";
    cin>>sales;
    return sales;
}
float calculateCommision(float sales, float percentage){
    return (sales * percentage) / 100;
}
float calculateSalary(float weeklySalary, float commission){
    return weeklySalary + commission;
}
void displayDetails(float commision, float sales, float percentage, float weeklySalary){
    float salary = calculateSalary(weeklySalary , commision);
    cout << "Commision = " << commision << " on Sales " << sales << " @ percentage " << percentage
         << "% , with base Salary " << weeklySalary << ", Gross Salary " << salary << endl;
}
void calculateSalaryRange(int salary,int salaryData[],int s){
    if(salary >= 200 && salary <= 299){
        salaryData[0]++;
    }else if(salary >= 300 && salary < 399){
        salaryData[1]++;
    }else if(salary >= 400 && salary < 499){
        salaryData[2]++;
    }else if(salary >= 500 && salary < 599){
        salaryData[3]++;
    }else if(salary >= 600 && salary < 699){
        salaryData[4]++;
    }else if(salary >= 700 && salary < 799){
        salaryData[5]++;
    }else if(salary >= 800 && salary < 899){
        salaryData[6]++;
    }else if(salary >= 900 && salary < 999){
        salaryData[7]++;
    }else if(salary >= 1000 ){
        salaryData[8]++;
    }
}
void displaySalaryRanges(int salaries[],int s){
    int initial = 200 , step = 99;
    for (int i = 0; i < s; ++i) {
        cout<<initial<<"$  to  "<<(initial + step)<<"$  "<<salaries[i]<<endl;
        initial += 100;
    }
}