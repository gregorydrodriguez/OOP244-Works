/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#include "Mark.h"

namespace sdds {
Mark::operator int() {
    if (!isValid) {
        return 0;
    }
    return m_mark;
}

Mark::operator double() {
    switch (m_mark) {
        case 0 ... 49:
            return m_gpa = 0;
        case 50 ... 59:
            return m_gpa = 1;
        case 60 ... 69:
            return m_gpa = 2;
        case 70 ... 79:
            return m_gpa = 3;
        case 80 ... 100:
            return m_gpa = 4;
        default:
            return m_gpa = 0;
    }
}

Mark::operator char() {
    switch (m_mark) {
        case 0 ... 49:
            return m_grade = 'F';
        case 50 ... 59:
            return m_grade = 'D';
        case 60 ... 69:
            return m_grade = 'C';
        case 70 ... 79:
            return m_grade = 'B';
        case 80 ... 100:
            return m_grade = 'A';
        default:
            return m_grade = 'X';
    }
}

Mark& Mark::operator+=(int value) {
    m_mark += value;
    checkValidity();
    return *this;
}

int& operator+=(int& value, Mark& mark) {
    value += int(mark);
    return value;
}

Mark& Mark::operator=(const int value) {
    m_mark = value;
    checkValidity();
    return *this;
}

void Mark::checkValidity() {
    if (m_mark < 0 || m_mark > 100) {
        isValid = false;
    } else {
        isValid = true;
    }
}

Mark::Mark() {
    m_mark = 0;
    isValid = true;
}

Mark::Mark(int mark) {
    m_mark = mark;
    checkValidity();
}
}  // namespace sdds