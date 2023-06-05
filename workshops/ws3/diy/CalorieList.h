/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez 
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
Date: June 4, 2023
*/
#ifndef SDDS_CALORIELIST_H
#define SDDS_CALORIELIST_H
#include "Food.h"
namespace sdds {

class CalorieList {
    Food* m_food;
    int m_noOfFood;
    int m_foodAdded;
    void title() const;
    void footer() const;
    void setEmpty();
    bool isValid() const;
    int totalCalories() const;

   public:
    void init(int noOfFood);
    bool add(const char* food_name, int calories, int timeOfConsumption);
    void display() const;
    void deallocate();
};

}  // namespace sdds
#endif  // SDDS_CALORIELIST_H