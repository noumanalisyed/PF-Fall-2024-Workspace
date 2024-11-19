#include <iostream>
using namespace std;

int main() {
    int x = 5;

    switch (x) {
        case 1:
            cout << "One";
        case 5:
            cout << "Five";
        default:
            cout << "Default";
    }
    return 0;
}
