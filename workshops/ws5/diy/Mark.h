/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#ifndef SDDS_MARK_H
#define SDDS_MARK_H
namespace sdds {
class Mark {
    int m_mark;
    double m_gpa;
    char m_grade;
    bool isValid;
    void checkValidity();

   public:
    Mark();
    Mark(int mark);
    operator int();
    operator double();
    operator char();
    Mark& operator+=(int value);
    Mark& operator=(const int value);
};

int& operator+=(int& value, Mark& mark);
}  // namespace sdds
#endif  // SDDS_MARK_H