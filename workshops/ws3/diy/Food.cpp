/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez 
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
Date: June 4, 2023
*/
#include "Food.h"

#include <cstring>
#include <iomanip>
#include <iostream>

#include "cstring.h"

using namespace std;

namespace sdds {

void Food::display() const {
    if (isValid()) {
        cout << "| " << left << setw(30) << setfill('.') << m_name << " | ";
        cout << right << setw(4) << setfill(' ') << m_calories << " | ";
        cout << left << setw(10) << getConsumptionTimeString() << " |" << endl;
    } else {
        cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
    }
}

bool Food::isValid() const {
    return (m_name[0] != '\0' || m_calories != 0 || (m_consumptionTime >= 1 && m_consumptionTime <= 4));
}

void Food::setName(const char* name) {
    strncpy(m_name, name, 30);
}

const char* Food::getConsumptionTimeString() const {
    switch (m_consumptionTime) {
        case 1:
            return "Breakfast";
        case 2:
            return "Lunch";
        case 3:
            return "Dinner";
        case 4:
            return "Snack";
        default:
            return "\0";
    };
}

void Food::setEmpty() {
    m_name[0] = '\0';
    m_calories = 0;
    m_consumptionTime = 0;
}

int Food::calories() const {
    return m_calories;
}

void Food::set(const char* name, int calories, const int consumption_time) {
    if (name == nullptr || calories <= 0 || (consumption_time < 1 || consumption_time > 4)) {
        setEmpty();
    } else {
        setName(name);
        m_calories = calories;
        m_consumptionTime = consumption_time;
    }
}

}  // namespace sdds

/*
+----------------------------------------------------+
|  Daily Calorie Consumption                         |
+--------------------------------+------+------------+
| Food name                      | Cals | When       |
+--------------------------------+------+------------+
| Cheerios Cereal with 2% milk.. |  170 | Breakfast  |
| Tim Hortons Medium coffee doub |  230 | Breakfast  |
| Cheeseburger.................. |  303 | Lunch      |
| French Fries.................. |  312 | Lunch      |
| Pepsi......................... |  150 | Lunch      |
| Apple......................... |   52 | Snack      |
| Bread and Cheese.............. |  195 | Dinner     |
| Garden Salad with Dressing.... |  220 | Dinner     |
| Red Wine...................... |   85 | Dinner     |
+--------------------------------+------+------------+
|    Total Calories for today:     1717 |            |
+----------------------------------------------------+
*/