#include <iostream>

using namespace std;

int mainq() {
    char grade;
    cout << "Enter Grade : ";
    cin >> grade;

    switch (grade) {
        case 'A':
        case 'a':
            cout << "Excellent!";
            break;
        case 'B':
        case 'b':
            cout << "Good Job!";
            break;
        case 'C':
        case 'c':
            cout << "Well Done!";
            break;
        default:
            cout << "Try Again!";
    }
    return 0;
}
