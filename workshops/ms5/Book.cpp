/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#include "Book.h"

#include <iomanip>
#include <iostream>
#include <string>
#include <limits>
#include <cstring>

using namespace std;
namespace sdds {
Book::operator bool() const {
    return m_author && Publication::operator bool();
}

void Book::set(int membershipNum) {
    Publication::set(membershipNum);
    Publication::resetDate();
}

istream& Book::read(istream& is) {
    Publication::read(is);
    char tempAuthor[256];
    delete[] m_author;
    m_author = nullptr;
    if (conIO(is)) {
        is.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Author: ";
        is.get(tempAuthor, 256);
    } else {
        is.ignore(numeric_limits<streamsize>::max(), '\t');
        is.get(tempAuthor, 256);
    }
    if (is.good()) {
        m_author = new char[strlen(tempAuthor) + 1];
        strcpy(m_author, tempAuthor);
    }
    return is;
}

ostream& Book::write(ostream& os) const {
    Publication::write(os);
    if (conIO(os)) {
        os << " ";
        if (strlen(m_author) > SDDS_AUTHOR_WIDTH) {
            os.write(m_author, SDDS_AUTHOR_WIDTH);
        } else {
            os << left << setw(SDDS_AUTHOR_WIDTH) << m_author;
        }
        os << " |";
    } else {
        os << '\t';
        os << m_author;
    }
    return os;
}

char Book::type() const {
    return 'B';
}

// Constructor
Book::Book() {
    m_author = nullptr;
}

// Copy Constructor
Book::Book(const Book& bookObject) : Publication(bookObject) {
    if (bookObject.m_author) {
        m_author = new char[strlen(bookObject.m_author) + 1];
        strcpy(m_author, bookObject.m_author);
    } else {
        setDefault();
        m_author = nullptr;
    }
}

// Copy Assignment
Book& Book::operator=(const Book& bookObject) {
    if (this != &bookObject) {
        delete[] m_author;
        m_author = nullptr;
        if (bookObject.m_author) {
            m_author = new char[strlen(bookObject.m_author) + 1];
            strcpy(m_author, bookObject.m_author);
        }
        Publication::operator=(bookObject);
    }

    return *this;
}

// Destructor
Book::~Book() {
    delete[] m_author;
}
}  // namespace sdds