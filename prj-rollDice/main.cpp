#include <iostream>
using namespace std;
long getRandomNo(int startingRange, int endingRange){
    long randomNo = 0;
    for(int i=0; i < 5; ) {
        long temp = startingRange + (std::rand() * 1000) % endingRange;
        if(temp > 0){
            randomNo = temp;
            i++;
            break;
        }
    }
    return randomNo;
}
void displayPossibleDicePositions(){
    const int row = 6, col = 6;
    int possibleData[row][col] = {
            {2,3,4,5,6,7},
            {3,4,5,6,7,8},
            {4,5,6,7,8,9},
            {5,6,7,8,9,10},
            {6,7,8,9,10,11},
            {7,8,9,10,11,12}
    };
    cout<<"\t\t1\t\t2\t\t3\t\t4\t\t5\t\t6\t\t"<<endl;
    for (int i = 0; i < row; ++i) {
        cout<<(i+1)<<". \t";
        for (int j = 0; j < col; ++j) {
            cout<<"\t"<<possibleData[i][j]<<"\t";
        }
        cout<<endl;
    }
}
int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
   // displayRandomNos(100, 1, 6);
    int dice1, dice2;
    int possibilities[13] = {0};
    displayPossibleDicePositions();
    for(int i=0; i< 36000; i++){
        dice1 = getRandomNo(1,6);
        dice2 = getRandomNo(1,6);
        //cout<<"dice1 = "<<dice1<<" , dice2 = "<<dice2<<" , No = "<<(dice1+dice2)<<endl;
        possibilities[dice2+dice1]++;
    }
    cout<<endl<<endl;
    for (int i = 1; i < 13; ++i) {
        cout<<i<<".  -->   "<<possibilities[i]<<endl;
    }
    return 0;
}
