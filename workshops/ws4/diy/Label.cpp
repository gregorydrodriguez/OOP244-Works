#include "Label.h"

#include <cstring>
#include <iostream>

#include "LabelMaker.h"

using namespace std;

namespace sdds {
void Label::setDefault() {
    m_frame = nullptr;
    m_content = nullptr;
}

void Label::setFrame(const char* frameArg) {
    delete[] m_frame;
    m_frame = new char[strlen(frameArg) + 1];
    strcpy(m_frame, frameArg);
}

void Label::setContent(const char* content) {
    delete[] m_content;
    m_content = new char[strlen(content) + 1];
    strcpy(m_content, content);
}

Label::Label() {
    setDefault();
    setFrame("+-+|+-+|");
}

Label::Label(const char* frameArg) {
    setDefault();
    setFrame(frameArg);
}

Label::Label(const char* frameArg, const char* content) {
    setDefault();
    setFrame(frameArg);
    setContent(content);
}

Label::~Label() {
    delete[] m_frame;
    delete[] m_content;
}

void Label::readLabel() {
    char temp[71];
    cin >> temp;
    cin.ignore(70, '\n');
    cin.clear();
    setContent(temp);
}

// 0 1 2
// 7   3
// 6 5 4
std::ostream& Label::printLabel() const {
    if (m_content != nullptr) {
        int len = strlen(m_content) + 2;
        cout << m_frame[0];
        for (int i = 0; i < len; i++) {
            cout << m_frame[1];
        };
        cout << m_frame[2] << endl;
        cout << m_frame[7];
        for (int i = 0; i < len; i++) {
            cout << " ";
        }
        cout << m_frame[3] << endl;
        cout << m_frame[7] << " " << m_content << " " << m_frame[3] << endl;
        cout << m_frame[7];
        for (int i = 0; i < len; i++) {
            cout << " ";
        }
        cout << m_frame[3] << endl;
        cout << m_frame[6];
        for (int i = 0; i < len; i++) {
            cout << m_frame[5];
        };
        cout << m_frame[4] << endl;
    }
    return cout;
}
}  // namespace sdds