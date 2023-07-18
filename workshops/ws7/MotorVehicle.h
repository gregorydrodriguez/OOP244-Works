/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#ifndef SDDS_MOTORVEHICLE_H
#define SDDS_MOTORVEHICLE_H
#include <iostream>
namespace sdds {
const int LICENSE_PLATE_LENGTH = 9;
const int ADDRESS_LENGTH = 64;

class MotorVehicle {
   protected:
    char m_licensePlate[LICENSE_PLATE_LENGTH]{};
    char m_address[ADDRESS_LENGTH]{};
    int m_year;

   public:
    MotorVehicle(const char* licensePlate = "VVV-111", const int year = 2010);
    void moveTo(const char* address);
    std::ostream& write(std::ostream& os) const;
    std::istream& read(std::istream& in);
};

std::ostream& operator<<(std::ostream& ostr, const MotorVehicle& vehicle);
std::istream& operator>>(std::istream& istr, MotorVehicle& vehicle);
}  // namespace sdds
#endif  // SDDS_MOTORVEHICLE_H