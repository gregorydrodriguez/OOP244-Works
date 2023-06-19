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
            return 0;
        case 50 ... 59:
            return 1;
        case 60 ... 69:
            return 2;
        case 70 ... 79:
            return 3;
        case 80 ... 100:
            return 4;
        default:
            return 0;
    }
}

Mark::operator char() {
    switch (m_mark) {
        case 0 ... 49:
            return 'F';
        case 50 ... 59:
            return 'D';
        case 60 ... 69:
            return 'C';
        case 70 ... 79:
            return 'B';
        case 80 ... 100:
            return 'A';
        default:
            return 'X';
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