/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include "Publication.h"

namespace sdds {
class Book : public Publication {
   private:
    char* m_author;

   public:
    Book();
    // Rule of 3
    Book(const Book& object);
    Book& operator=(const Book& object);
    ~Book();

    char type() const;
    std::ostream& write(std::ostream& os) const;
    std::istream& read(std::istream& is);
    void set(int membershipNum);
    operator bool() const;
};
}  // namespace sdds
#endif  // SDDS_BOOK_H