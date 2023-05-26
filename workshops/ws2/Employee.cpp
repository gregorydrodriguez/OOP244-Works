#include "Employee.h"

#include <iostream>

#include "File.h"
#include "cstring.h"  // implemented in workshop 1 part 2 (DIY)
using namespace std;
namespace sdds {

int noOfEmployees;
Employee* employees;

void sort() {
    int i, j;
    Employee temp;
    for (i = noOfEmployees - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (employees[j].m_empNo > employees[j + 1].m_empNo) {
                temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }
}

// TODO: Finish the implementation of the 1 arg load function which
// reads one employee record from the file and loads it into the employee reference
// argument
bool load(Employee& employee) {
    bool ok = false;
    char name[128];
    int empNo;
    double salary;

    // if (fscanf(, "%d,%lf,%s\n", empNo, salary, name) == 3) {
    if (read(empNo) && read(salary) && read(name)) {
        // If all reads are successful
        employee.m_name = new char[strLen(name) + 1];
        strCpy(employee.m_name, name);
        employee.m_empNo = empNo;
        employee.m_salary = salary;
        ok = true;
    }
    /* if reading of employee number, salay and name are successful
            allocate memory to the size of the name + 1
            and keep its address in the name of the Employee Reference

            copy the name into the newly allocated memroy

            make sure the "ok" flag is set to true
       end if
    */
    return ok;
}

// TODO: Finish the implementation of the 0 arg load function
bool load() {
    bool ok = false;
    int i = 0;
    if (openFile(DATAFILE)) {
        noOfEmployees = noOfRecords();
        employees = new Employee[noOfEmployees];
        while (load(employees[i])) {
            i++;
        }
        // noOfRecords() returns 13 when there are 14 records
        // because there is no new line at the end of the csv
        if (noOfEmployees != (i)) {
            cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
        } else {
            ok = true;
        }
        closeFile();
        /*
         Set the noOfEmployees to the number of recoreds in the file.
         Dynamically allocate an array of employees into the global
         Employee pointer "employees"; the size of "employees" is noOfEmployees.

         In a loop load the employee records from the file into
         the dynamic array.

         If the number of the records does not match the number of reads
            print the message
           "Error: incorrect number of records read; the data is possibly corrupted"
         Otherwise
            set the ok flag to true
         End if

         close the file
         */
    } else {
        cout << "Could not open data file: " << DATAFILE << endl;
    }
    return ok;
}

// TODO: Implementation for the display functions go here
void display(const Employee& employee) {
    cout << employee.m_empNo << ": " << employee.m_name << ", " << employee.m_salary << endl;
}

void display() {
    cout << "Employee Salary report, sorted by employee number" << endl;
    cout << "no- Empno, Name, Salary" << endl;
    cout << "------------------------------------------------" << endl;
    sort();
    int i;
    for (i = 0; i < noOfEmployees; i++) {
        cout << i + 1 << "- ";
        display(employees[i]);
    }
}

// TODO: Implementation for the deallocateMemory function goes here
void deallocateMemory() {
    int i;
    for (i = 0; i < noOfEmployees; i++) {
        delete employees[i].m_name;
    }
    delete[] employees;
    employees = nullptr;
}
}  // namespace sdds