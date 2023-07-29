#include "Publication.h"

#include <cstring>
#include <iomanip>

using namespace std;
namespace sdds {

/* Publication Object */
Publication::Publication() {
    m_title = nullptr;
    strcpy(m_shelfID, "");
    m_membership = 0;
    m_libRef = -1;
    // date??
}

void Publication::set(int member_id) {
    if (member_id >= 10000 && member_id <= 99999) {
        m_membership = member_id;
    } else {
        m_membership = 0;
    }
}

void Publication::setRef(int value) {
    if (value > -1) {
        m_libRef = value;
    }
}

void Publication::resetDate() {
    m_date.setToToday();
}

char Publication::type() const {
    return 'P';
}

bool Publication::onLoan() const {
    return m_membership > 0;
}

Date Publication::checkoutDate() const {
    return m_date;
}

bool Publication::operator==(const char* title) const {
    char* truth;
    truth = strstr(m_title, title);
    return truth != NULL;
}

Publication::operator const char*() const {
    return m_title;
}

int Publication::getRef() const {
    return m_libRef;
}

bool Publication::conIO(ios& io) const {
    return (&io == &cin || &io == &cout);
}

ostream& Publication::write(ostream& os) const {
    if (conIO(os)) {
        os << "| " << m_shelfID << " | ";
        os << left << setw(SDDS_TITLE_WIDTH) << setfill('.') << m_title;
        os << " | ";
        onLoan() ? os << m_membership : os << " N/A ";
        os << " | " << m_date << " |";
    } else {
        os << '\n';
        os << type() << "\t";
        os << m_libRef << "\t";
        os << m_shelfID << "\t";
        os << m_title << "\t";
        onLoan() ? os << m_membership : os << " N/A ";
        os << "\t";
        os << m_date;
    }
    return os;
}

istream& Publication::read(istream& istr) {
    // local variables
    char tempTitle[255];
    char tempShelfID[255];
    int tempMembership = 0;
    int tempLibRef = -1;
    Date tempDate;
    // set attributes to default
    delete[] m_title;
    m_title = nullptr;
    strcpy(m_shelfID, "");
    m_membership = 0;
    m_libRef = -1;

    if (conIO(istr)) {
        cout << "Shelf No: ";
        istr.getline(tempShelfID, SDDS_SHELF_ID_LEN + 1);
        if (strlen(tempShelfID) != SDDS_SHELF_ID_LEN) {
            istr.setstate(ios::failbit);
        }
        cout << "Title: ";
        istr.getline(tempTitle, 255);
        cout << "Date: ";
        istr >> tempDate;
    } else {
        istr >> tempLibRef;
        istr.ignore(1000, '\t');
        istr.getline(tempShelfID, SDDS_SHELF_ID_LEN + 1, '\t');
        istr.getline(tempTitle, 255, '\t');
        istr >> tempMembership;
        istr.ignore(1000, '\t');
        istr >> tempDate;
    }
    if (tempDate.validate() == false) {
        istr.setstate(ios::failbit);
    }

    if (istr.good()) {
        m_title = new char[strlen(tempTitle) + 1];
        strcpy(m_title, tempTitle);
        strcpy(m_shelfID, tempShelfID);
        m_membership = tempMembership;
        m_libRef = tempLibRef;
        m_date = tempDate;
    }
    return istr;
}

Publication::operator bool() const {
    return m_title != nullptr && m_title[0] != '\0' && m_shelfID[0] != '\0';
}

// Rule of 3
Publication::Publication(const Publication& object) {
    if (this != &object) {
        delete[] m_title;
        m_title = new char[strlen(object.m_title) + 1];
        strcpy(m_title, object.m_title);
        strcpy(m_shelfID, object.m_shelfID);
        m_membership = object.m_membership;
        m_libRef = object.m_libRef;
        m_date = object.m_date;
    }
}

Publication& Publication::operator=(const Publication& object) {
    if (this != &object) {
        delete[] m_title;
        m_title = nullptr;
        if (object.m_title != nullptr) {
            m_title = new char[strlen(object.m_title) + 1];
            strcpy(m_title, object.m_title);
        }
        strcpy(m_shelfID, object.m_shelfID);
        m_membership = object.m_membership;
        m_libRef = object.m_libRef;
        m_date = object.m_date;
    }
    return *this;
}

Publication::~Publication() {
    delete[] m_title;
}

}  // namespace sdds