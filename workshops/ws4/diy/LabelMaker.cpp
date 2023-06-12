/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez 
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
Date: June 12, 2023
*/
#include "LabelMaker.h"

#include <iostream>

using namespace std;

namespace sdds {
LabelMaker::LabelMaker(int noOfLabels) {
    m_noOfLabels = noOfLabels;
    m_labels = new Label*[m_noOfLabels];
    for (int i = 0; i < m_noOfLabels; i++) {
        m_labels[i] = new Label();
    }
}

void LabelMaker::readLabels() {
    cout << "Enter " << m_noOfLabels << " labels:" << endl;
    for (int i = 0; i < m_noOfLabels; i++) {
        cout << "Enter label number " << i + 1 << endl;
        cout << "> ";
        m_labels[i]->readLabel();
    }
}

void LabelMaker::printLabels() {
    for (int i = 0; i < m_noOfLabels; i++) {
        m_labels[i]->printLabel();
    }
}

LabelMaker::~LabelMaker() {
    for (int i = 0; i < m_noOfLabels; i++) {
        delete m_labels[i];
    }
    delete[] m_labels;
}
}  // namespace sdds