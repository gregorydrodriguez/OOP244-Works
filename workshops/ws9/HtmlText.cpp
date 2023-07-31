/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
Date: July 30, 2023
*/
#include "HtmlText.h"
#include <cstring>
namespace sdds {
HtmlText::HtmlText(const char* filename, const char* title) : Text(filename) {
    if (filename) {
        (Text(filename));
    } else {
        setDefault();
    }
    if (title) {
        m_title = new char[strlen(title) + 1];
        strcpy(m_title, title);
    } else {
        m_title = nullptr;
    }
}

void HtmlText::write(std::ostream& os) const {
    os << "<html><head><title>" << (m_title ? m_title : "No Title") << "</title></head>\n<body>\n";
    os << "<h1>" << (m_title ? m_title : "No Title") << "</h1>\n";
    int i = 0;
    bool multipleSpaces = false;
    while ((*this)[i]) {
        switch ((*this)[i]) {
            case ' ':
                if (multipleSpaces) {
                    os << "&nbsp;";
                } else {
                    os << ' ';
                    multipleSpaces = true;
                }
                break;
            case '<':
                os << "&lt;";
                multipleSpaces = false;
                break;
            case '>':
                os << "&gt";
                multipleSpaces = false;
                break;
            case '\n':
                os << "<br />\n";
                multipleSpaces = false;
                break;
            default:
                os << (*this)[i];
                multipleSpaces = false;
                break;
        }
        i++;
    }
    os << "</body>\n</html>";
}

// rule of three
HtmlText::HtmlText(const HtmlText& htmlObject) : Text(htmlObject) {
    if (htmlObject.m_title) {
        m_title = new char[strlen(htmlObject.m_title) + 1];
        strcpy(m_title, htmlObject.m_title);
    } else {
        setDefault();
        m_title = nullptr;
    }
}

HtmlText& HtmlText::operator=(HtmlText& htmlObject) {
    if (this != &htmlObject) {
        delete[] m_title;
        m_title = new char[strlen(htmlObject.m_title) + 1];
        strcpy(m_title, htmlObject.m_title);
        Text::operator=(htmlObject);
    }
    return *this;
}

HtmlText::~HtmlText() {
    delete[] m_title;
}
}  // namespace sdds