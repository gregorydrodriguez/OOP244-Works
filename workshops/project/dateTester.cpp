// Final Project
// Date Tester program
// File	dateTester.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Description
// This programs test the student coding to complete of the Date class
//
// When testing before submission: DO NOT MODIFY THIS FILE IN ANY WAY
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;
#include "Date.h"
using namespace sdds;

// A fool proof Date entry from console
Date getDate();

int main() {
    Date
        D1,  // daysSince0001_1_1 to be recieved from console
        D2(2023, 6, 26);

    cout << "Current Date: " << D1 << endl;
    cout << D1 - D2 << " days since ms1 was published" << endl;
    cout << "Please enter a date to be compared to " << D2 << endl
         << "(Also try some invalid values for testing): " << endl
         << "YYYY/MM/DD > ";
    D1 = getDate();
    cout << "Your Entry: " << D1 << endl;
    cout << "Set by program to 2023/06/26: " << D2 << endl;
    cout << "Days between the two dates: " << D1 - D2 << endl;
    cout << "All the following statements must be correct: " << endl;
    if (D1 > D2) {
        cout << D1 << " > " << D2 << endl;
    } else {
        cout << D1 << " <= " << D2 << endl;
    }
    if (D1 < D2) {
        cout << D1 << " < " << D2 << endl;
    } else {
        cout << D1 << " >= " << D2 << endl;
    }
    if (D1 <= D2) {
        cout << D1 << " <= " << D2 << endl;
    } else {
        cout << D1 << " > " << D2 << endl;
    }
    if (D1 >= D2) {
        cout << D1 << " >= " << D2 << endl;
    } else {
        cout << D1 << " < " << D2 << endl;
    }
    if (D1 == D2) {
        cout << D1 << " == " << D2 << endl;
    } else {
        cout << D1 << " != " << D2 << endl;
    }
    if (D1 != D2) {
        cout << D1 << " != " << D2 << endl;
    } else {
        cout << D1 << " == " << D2 << endl;
    }
    return 0;
}

Date getDate() {
    Date D;
    do {
        cin >> D;                                                       // get D from console
    } while (!D && cout << D.dateStatus() << ", Please try again > ");  // if D is invalid, print error message and loop
    return D;
}