#include <iostream>

using namespace std;

int main() {
    int rowSize , colSize;
    char ch;
    cout<<"Enter Row Size ";
    cin>>rowSize;
    cout<<"Enter Column Size ";
    cin>>colSize;
    cout<<"Enter the Board character ";
    cin>>ch;
    int row = 1;
    while (row <= rowSize) {
        int col = 1;
        while (col <= colSize) {
            if(row > col ){
                cout << " ";
            }
            else{
                cout<<ch;
            }
            col++;
        }
        cout << "\n";
        row ++;
    }
    return 0;
}
