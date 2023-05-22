#include <iostream>
#include "Student.h"
using namespace std;
using namespace sdds;
int main() {

    Student S, T;

    S.set();
    T.set("Rania", 1234);

    S.display();
    T.display();

    S.deallocate();
    T.deallocate();

    return 0;
    // int* a = new int;
    // int size = 0;
    // int* arrayptr = nullptr;

    // cout << "Enter the number of students " << endl;
    // cin >> size;

    // arrayptr = new int[size];
    // if (arrayptr == nullptr) {
    //     cout << "No memory" << endl;
    // } else {
    //     for (int i = 0; i < size; i++) {
    //         cout << "Enter element " << i + 1 << ":";
    //         cin >> arrayptr[i];
    //     }
    //     for (int i = 0; i < size; i++) {
    //         cout << arrayptr[i] << " - ";
    //     }
    // }

    // delete a;
    // delete[] arrayptr;

}