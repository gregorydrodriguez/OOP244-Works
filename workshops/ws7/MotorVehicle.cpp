/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#include "MotorVehicle.h"

#include <cstring>
#include <iomanip>
#include <iostream>
#include <limits>

using namespace std;
namespace sdds {
    
// Motor Vehicle Class Methods (parent)
MotorVehicle::MotorVehicle(const char* licensePlate, const int year) {
    strcpy(m_licensePlate, licensePlate);
    m_year = year;
    strcpy(m_address, "Factory");
}

void MotorVehicle::moveTo(const char* address) {
    if (m_address != address) {
        cout << "|" << right << setw(8) << m_licensePlate;
        cout << "| |" << right << setw(20) << m_address << " ---> ";
        cout << left << setw(20) << address << "|" << endl;
        strcpy(m_address, address);
    }
}

ostream& MotorVehicle::write(ostream& os) const {
    os << "| " << m_year << " | " << m_licensePlate << " | " << m_address;
    return os;
}

istream& MotorVehicle::read(istream& in) {
    cout << "Built year: ";
    in >> m_year;
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "License plate: ";
    in >> m_licensePlate;
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Current location: ";
    in.getline(m_address, ADDRESS_LENGTH);
    return in;
}

// Helper Functions
ostream& operator<<(ostream& ostr, const MotorVehicle& vehicle) {
    return vehicle.write(ostr);
}

istream& operator>>(istream& istr, MotorVehicle& vehicle) {
    return vehicle.read(istr);
}
}  // namespace sdds