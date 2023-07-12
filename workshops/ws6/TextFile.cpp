/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#include "TextFile.h"

#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
namespace sdds {
Line::operator const char*() const {
    return (const char*)m_value;
}
Line& Line::operator=(const char* lineValue) {
    delete[] m_value;
    m_value = new char[strlen(lineValue) + 1];
    strcpy(m_value, lineValue);
    return *this;
}
Line::~Line() {
    delete[] m_value;
}

void TextFile::setEmpty() {
    delete[] m_textLines;
    m_textLines = nullptr;
    delete[] m_filename;
    m_filename = nullptr;
    m_noOfLines = 0;
}

void TextFile::setFilename(const char* fname, bool isCopy) {
    if (!isCopy) {
        delete[] m_filename;
        m_filename = new char[strlen(fname) + 1];
        strcpy(m_filename, fname);
    } else {
        delete[] m_filename;
        m_filename = new char[strlen(fname) + 3];
        strcpy(m_filename, "C_");
        strcat(m_filename, fname);
    }
}

void TextFile::setNoOfLines() {
    ifstream file(m_filename);
    char ch;
    while (file.get(ch)) {
        if (ch == '\n') {
            m_noOfLines++;
        }
    }
    if (!m_noOfLines) {
        setEmpty();
    }
    m_noOfLines++;
    file.close();
}

void TextFile::loadText() {
    if (m_filename) {
        delete[] m_textLines;
        m_textLines = nullptr;
        m_textLines = new Line[m_noOfLines];
        ifstream file(m_filename);
        string line;
        int i = 0;
        while (getline(file, line)) {
            m_textLines[i] = line.c_str();
            i++;
        }
        m_noOfLines = i;
        file.close();
    }
}

void TextFile::saveAs(const char* fileName) const {
    ofstream file(fileName);
    for (unsigned int i = 0; i < m_noOfLines; i++) {
        file << m_textLines[i] << endl;
    }
    file.close();
}

TextFile::TextFile(unsigned pageSize) {
    setEmpty();
    m_pageSize = pageSize;
}

TextFile::TextFile(const char* filename, unsigned pageSize) {
    setEmpty();
    m_pageSize = pageSize;
    if (filename) {
        setFilename(filename);
        setNoOfLines();
        loadText();
    }
}

TextFile::TextFile(const TextFile& srcFile) {
    setEmpty();
    m_pageSize = srcFile.m_pageSize;
    if (srcFile) {
        setFilename(srcFile.m_filename, true);
        srcFile.saveAs(m_filename);
        setNoOfLines();
        loadText();
    }
}

TextFile& TextFile::operator=(const TextFile& incFile) {
    if (*this && incFile) {
        setEmpty();
        setFilename(incFile.m_filename, false);
        incFile.saveAs(m_filename);
        setNoOfLines();
        loadText();
    }
    return *this;
}

TextFile::~TextFile() {
    delete[] m_textLines;
    delete[] m_filename;
}

unsigned TextFile::lines() const {
    return m_noOfLines;
}

ostream& TextFile::view(ostream& ostr) const {
    if (*this) {
        ostr << m_filename << endl;
        unsigned int i, j;
        for (i = 0; i < strlen(m_filename); i++) {
            ostr << '=';
        }
        ostr << endl;
        for (i = 0; i < m_noOfLines; i++) {
            ostr << m_textLines[i] << endl;
            j++;
            if (j == m_pageSize) {
                ostr << "Hit Enter to continue...";
                cin.ignore();
                j = 0;
            }
        }
    }
    return ostr;
}

istream& TextFile::getFile(istream& istr) {
    string fname;
    istr >> fname;
    istr.ignore();
    setFilename(fname.c_str());
    setNoOfLines();
    loadText();
    return istr;
}

const char* TextFile::operator[](unsigned index) const {
    if (!(*this)) {
        return nullptr;
    }
    if (index >= m_noOfLines) {
        index %= m_noOfLines;
    }
    return m_textLines[index].m_value;
}

TextFile::operator bool() const {
    return !(m_filename == nullptr && m_textLines == nullptr);
}

const char* TextFile::name() const {
    return m_filename;
}

ostream& operator<<(ostream& ostr, const TextFile& text) {
    text.view(ostr);
    return ostr;
}

istream& operator>>(istream& istr, TextFile& text) {
    text.getFile(istr);
    return istr;
}
}  // namespace sdds