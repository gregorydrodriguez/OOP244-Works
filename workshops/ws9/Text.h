/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
Date: July 30, 2023
*/
#ifndef SDDS_TEXT_H
#define SDDS_TEXT_H
#include <iostream>
namespace sdds {
class Text {
    char* m_filename;
    char* m_content;
    int getFileLength() const;  // Code provided in Text.cpp
   protected:
    const char& operator[](int index) const;

   public:
    Text(const char* filename = nullptr);
    // implement rule of three here
    Text(const Text& textObject);
    Text& operator=(Text& textObject);
    virtual ~Text();

    void setDefault();
    void read();
    virtual void write(std::ostream& os) const;
};
// prototype of insertion overload into ostream goes here
std::ostream& operator<<(std::ostream& os, const Text& textObject);
}  // namespace sdds
#endif  // SDDS_TEXT_H