#ifndef SDDS_STUDENT_H
#define SDDS_STUDENT_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
namespace sdds {

struct Student {

    private:
    char* name{}; // same as: char* name{nullptr} || char* name = nullptr
    int id;

    public:
    void set();
    void set(const char name[], int stdid);
    void display();
    void deallocate();
}

} // namespace sdds

#endif // SDDS_STUDENT_H