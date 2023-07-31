/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
Date: July 30, 2023
*/
#include "Text.h"

#include <cstring>
#include <fstream>
#include <string>

using namespace std;

namespace sdds {
void Text::setDefault() {
    m_filename = nullptr;
    m_content = nullptr;
}

Text::Text(const char* filename) {
    setDefault();
    if (filename) {
        ifstream fin(filename);
        m_filename = new char[strlen(filename) + 1];
        strcpy(m_filename, filename);
        this->read();
        fin.close();
    }
}

const char& Text::operator[](int index) const {
    return m_content[index];
}

int Text::getFileLength() const {
    int len = 0;
    ifstream fin(m_filename);
    while (fin) {
        fin.get();
        len += !!fin;
    }
    return len;
}

// Rule of 3
// Copy Constructor
Text::Text(const Text& textObject) {
    if (textObject.m_filename != nullptr) {
        m_filename = new char[strlen(textObject.m_filename) + 1];
        strcpy(m_filename, textObject.m_filename);
        if (textObject.m_content != nullptr) {
            m_content = new char[strlen(textObject.m_content) + 1];
            strcpy(m_content, textObject.m_content);
        }
    } else {
        setDefault();
    }
}

// Copy Assignment Operator
Text& Text::operator=(Text& textObject) {
    if (this != &textObject) {
        delete[] m_filename;
        delete[] m_content;
        m_filename = new char[strlen(textObject.m_filename) + 1];
        m_content = new char[strlen(textObject.m_content) + 1];
        strcpy(m_filename, textObject.m_filename);
        strcpy(m_content, textObject.m_content);
    }
    return *this;
}

// Destructor
Text::~Text() {
    delete[] m_filename;
    delete[] m_content;
}

void Text::read() {
    delete[] m_content;
    ifstream fin(m_filename);
    if (fin.fail()) {
        setDefault();
    } else {
        m_content = new char[getFileLength() + 2];
        string tempContent;
        string line;
        while (getline(fin, line)) {
            tempContent += line + '\n';
        }
        strcpy(m_content, tempContent.c_str());
        m_content[getFileLength()] = '\0';
    }
    fin.close();
}

void Text::write(std::ostream& os) const {
    if (m_content != nullptr) {
        os << m_content;
    }
}

ostream& operator<<(ostream& os, const Text& textObject) {
    textObject.write(os);
    return os;
}
}  // namespace sdds