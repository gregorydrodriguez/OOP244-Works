#include "LblShape.h"

#include <iostream>
#include <string>
#include <cstring>

using namespace std;
namespace sdds {
// Protected:
const char* LblShape::label() const {
    return m_label;
}

// Public:
LblShape::LblShape() {
    m_label = nullptr;
}

LblShape::LblShape(const char* labelName) {
    delete[] m_label;
    m_label = new char[strlen(labelName) + 1];
    strcpy(m_label, labelName);
}

LblShape::~LblShape() {
    delete[] m_label;
}

//is.get & is.ignore
void LblShape::getSpecs(std::istream& is) {
    string temp;
    getline(is, temp, ',');
    const char* labelName = temp.c_str();
    delete[] m_label;
    m_label = new char[strlen(labelName) + 1];
    strcpy(m_label, labelName);
}
}  // namespace sdds