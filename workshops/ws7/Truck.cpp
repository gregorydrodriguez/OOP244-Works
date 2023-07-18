/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#include "Truck.h"

#include <cstring>
#include <limits>
#include "MotorVehicle.h"

using namespace std;

namespace sdds {
Truck::Truck(const char* licensePlate, const int year, const double capacity, const char* address) {
    MotorVehicle(licensePlate, year);
    m_capacity = capacity;
    strcpy(m_address, address);
    m_cargo = 0;
}

bool Truck::addCargo(double cargo) {
    if (m_capacity > m_cargo + cargo) {
        m_cargo += cargo;
        return true;
    }
    return false;
}

bool Truck::unloadCargo() {
    if (m_cargo > 0) {
        m_cargo = 0;
        return true;
    }
    return false;
}

ostream& Truck::write(ostream& os) const {
    os << "| " << m_year << " | " << m_licensePlate << " | " << m_address << " | " << m_cargo << "/" << m_capacity;
    return os;
}

istream& Truck::read(istream& in) {
    cout << "Built year: ";
    in >> m_year;
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "License plate: ";
    in >> m_licensePlate;
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Current location: ";
    in.getline(m_address, ADDRESS_LENGTH);
    cout << "Capacity: ";
    in >> m_capacity;
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Cargo: ";
    in >> m_cargo;
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    return in;
}

// Helper Functions
ostream& operator<<(ostream& ostr, const Truck& truck) {
    return truck.write(ostr);
}

istream& operator>>(istream& istr, Truck& truck) {
    return truck.read(istr);
}
}  // namespace sdds