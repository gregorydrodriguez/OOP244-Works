/*
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student ID: 127880227
Workshop 1
w1p1.cpp
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Canister.h"

#include <cstring>
#include <iomanip>
#include <iostream>

#include "cstring.h"  // using strLen, strCpy and strCmp
using namespace std;
namespace sdds {
const double PI = 3.14159265;

void Canister::setToDefault() {
    m_contentName = nullptr;
    m_diameter = 10.0;
    m_height = 13.0;
    m_contentVolume = 0.0;
    m_usable = true;
}

bool Canister::isEmpty() const {
    if (m_contentVolume < 0.00001) {
        return true;
    }
    return false;
}

bool Canister::hasSameContent(const Canister& C) const {
    if (m_contentName[0] == '\0' && C.m_contentName[0] == '\0') {
        return false;
    }
    return (strcmp(m_contentName, C.m_contentName) == 0);
}

void Canister::setName(const char* Cstr) {
    if (Cstr != nullptr && m_usable == true) {
        delete[] m_contentName;
        m_contentName = new char[strlen(Cstr) + 1];
        strcpy(m_contentName, Cstr);
    }
}

Canister::Canister() {
    setToDefault();
}

Canister::Canister(const char* contentName) {
    setToDefault();
    setName(contentName);
}

Canister::Canister(double height, double diameter, const char* contentName) {
    setToDefault();
    if (height >= 10.0 && height <= 40.0 &&
        diameter >= 10.0 && diameter <= 30.0) {
        m_height = height;
        m_diameter = diameter;
        m_contentVolume = 0.0;
        setName(contentName);
    } else {
        m_usable = false;
    }
}

Canister::~Canister() {
    clear();
}

void Canister::clear() {
    delete[] m_contentName;
    m_contentName = nullptr;
    m_contentVolume = 0.0;
    m_usable = true;
}

double Canister::capacity() const {
    return PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);
}

double Canister::volume() const {
    return m_contentVolume;
}

Canister& Canister::setContent(const char* contentName) {
    if (contentName == nullptr) {
        m_usable = false;
    } else if (isEmpty()) {
        setName(contentName);
    } else if (!hasSameContent(contentName)) {
        m_usable = false;
    }
    return *this;
}

Canister& Canister::pour(double quantity) {
    if (m_usable == true && quantity > 0 &&
        (quantity + volume()) <= capacity()) {
        m_contentVolume += quantity;
    } else {
        m_usable = false;
    }
    return *this;
}

Canister& Canister::pour(Canister& C) {
    if (isEmpty()) {
        setName(C.m_contentName);
    }
    m_usable = hasSameContent(C);
    double roomLeft = capacity() - volume();
    if (C.volume() > roomLeft) {
        C.m_contentVolume -= roomLeft;
        m_contentVolume = capacity();
    } else {
        pour(C.m_contentVolume);
        C.m_contentVolume = 0.0;
    }
    if (m_contentVolume > capacity()) {
        m_usable = false;
    }
    return *this;
}

std::ostream& Canister::display() const {
    cout << right << setw(7) << fixed << setprecision(1) << capacity() << "cc ("
         << m_height << "x" << m_diameter << ") Canister";
    if (m_usable) {
        if (m_contentName != nullptr) {
            cout << " of " << right << setw(7) << m_contentVolume << "cc   " << m_contentName;
        }
    } else {
        cout << " of Unusable content, discard!";
    }
    return cout;
}
}  // namespace sdds