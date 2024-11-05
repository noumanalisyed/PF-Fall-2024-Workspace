#include <iostream>
using namespace std;
int main() {

   /* int row = 1;
    while( row <= 5){
        int col = 1;

        while(col <= 5){
            cout<<" * ";
            col++;
        }
        cout<<endl;
        row++;
    }*/

    /*int row = 1;
    while( row <= 5){
        int col = 1;
        while(col <= row){
            cout<<"*";
            col++;
        }
        cout<<endl;
        row++;
    }*/

    /*int row = 1;
    while( row <= 5){
        int col = 1;
        while(col <= 5){
            if(row > col)
                cout<<" ";
            else
                cout<<"*";
            col++;
        }
        cout<<endl;
        row++;
    }*/

    int row = 1;
    while( row <= 5){
        int col = 5;
        while(col >= 1){
            if(col > row)
                cout<<" ";
            else
                cout<<"*";
            col--;
        }
        cout<<endl;
        row++;
    }


    return 0;
}
