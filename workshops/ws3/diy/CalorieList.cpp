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
class CalorieList {

    char m_title[30];
    Food* m_food;
    int m_noOfFood;
    int m_foodAdded;
    int totalCalories;
    void Title() const;
    void footer() const;
    void setEmpty();
    bool isValid();

    public:
    void init(const char* title, int noOfFood);
    bool add(const char* food_name, int calories, int timeOfConsumption);
    void display() const;
    void deallocate();
};
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