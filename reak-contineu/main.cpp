// Fig. 5.13: BreakTest.cpp
// break statement exiting a for statement.
#include <iostream>
using namespace std;

int main() {
    unsigned int count; // control variable also used after loop

    for (count = 1; count <= 10; count++) { // loop 10 times
        if (count == 5) {
            break; // terminates loop if count is 5
        }
        cout << count << " ";
    }

    cout << "\nBroke out of loop at count = " << count << endl;

    int count1;
    for (count1 = 1; count1 <= 10; count1++) { // loop 10 times
        if (count1 == 5) {
            continue; // terminates loop if count is 5
        }
        cout << count1 << " ";
    }
    cout << "\nContineu out of loop at count = " << count1 << endl;
}
