/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez 
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
Date: June 4, 2023
*/

#include "CalorieList.h"

#include <iomanip>
#include <iostream>

#include "Food.h"

using namespace std;

namespace sdds {

void CalorieList::setEmpty() {
    m_food = nullptr;
}

bool CalorieList::isValid() const {
    if (m_food == nullptr) {
        return false;
    }

    int i = 0;
    for (i = 0; i < m_noOfFood; i++) {
        if (!m_food[i].isValid()) {
            return false;
        }
    }
    return true;
}

void CalorieList::title() const {
    cout << "+----------------------------------------------------+" << endl;
    if (isValid()) {
        cout << "|  Daily Calorie Consumption                         |" << endl;
    } else {
        cout << "| Invalid Calorie Consumption list                   |" << endl;
    }
    cout << "+----------------------------------------------------+" << endl;
    cout << "| Food name                      | Cals | When       |" << endl;
    cout << "+--------------------------------+------+------------+" << endl;
}

void CalorieList::footer() const {
    cout << "+--------------------------------+------+------------+" << endl;
    if (isValid()) {
        cout << "|    Total Calories for today:" << right << setw(9) << totalCalories() << " |            |" << endl;
    } else {
        cout << "|    Invalid Calorie Consumption list                |" << endl;
    }
    cout << "+----------------------------------------------------+" << endl;
}

int CalorieList::totalCalories() const {
    int i;
    int totalCal = 0;
    for (i = 0; i < m_noOfFood; i++) {
        totalCal += m_food[i].calories();
    }
    return totalCal;
}

void CalorieList::init(int noOfFood) {
    if (noOfFood <= 0) {
        setEmpty();
    } else {
        m_noOfFood = noOfFood;
        m_foodAdded = 0;
        m_food = new Food[noOfFood];
        int i;
        for (i = 0; i < noOfFood; i++) {
            Food food = Food();
            food.setEmpty();
            m_food[i] = food;
        }
    }
}

bool CalorieList::add(const char* food_name, int calories, int consumption_time) {
    if (m_foodAdded < m_noOfFood) {
        m_food[m_foodAdded].set(food_name, calories, consumption_time);
        m_foodAdded++;
        return true;
    } else {
        return false;
    }
}

void CalorieList::display() const {
    title();
    int i = 0;
    for (i = 0; i < m_noOfFood; i++) {
        m_food[i].display();
    }
    footer();
}

void CalorieList::deallocate() {
    delete[] m_food;
    m_food = nullptr;
}
}  // namespace sdds