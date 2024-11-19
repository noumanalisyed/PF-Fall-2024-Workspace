#include <iostream>
using namespace std;

int mainw() {
    int number = 2;

    switch (number) {
        case 1:
            cout << "One";
            break;
        case 2:
            cout << "Two";
            break;
        case 3:
            cout << "Three";
            break;
        default:
            cout << "Invalid Number";
    }

    return 0;
}
