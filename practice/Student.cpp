#include "Student.h"

using namespace std;

void sdds::Student::deallocate() {
    delete[] name;
    name = nullptr;
}

void sdds::Student::set() {
    cout << "Enter the student name " << endl;
    char tempName[50];
    // cin >> name;
    cin.getline(tempName, 50);
    name = new char[strlen(tempName + 1)];
    strcpy(tempName, name);

    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
    }
    
    //cin.getline()
    cout << "Enter the student ID " << endl;
    cin >> id;
        if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
    }


}

void sdds::Student::set(const char name[], int stdid) {
    name = new char[strlen(stdName) + 1];
    strncpy(name, stdName, 50);
    id = stdid;
}

void sdds::Student::display() {
    cout << "Student Name is " << name << ", ID is " << id << endl;
}