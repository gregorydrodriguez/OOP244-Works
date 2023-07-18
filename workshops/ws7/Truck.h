/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#ifndef SDDS_TRUCK_H
#define SDDS_TRUCK_H
#include "MotorVehicle.h"
namespace sdds {
class Truck : public MotorVehicle {
   private:
    double m_capacity;
    double m_cargo;

   public:
    Truck(const char* licensePlate, const int year, const double capacity, const char* address);
    bool addCargo(double cargo);
    bool unloadCargo();
    std::ostream& write(std::ostream& os) const;
    std::istream& read(std::istream& in);
};

std::ostream& operator<<(std::ostream& ostr, const Truck& truck);
std::istream& operator>>(std::istream& istr, Truck& truck);
}  // namespace sdds
#endif  // SDDS_TRUCK_H