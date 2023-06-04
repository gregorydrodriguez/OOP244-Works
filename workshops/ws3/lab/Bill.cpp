#include "Bill.h"

#include <iomanip>
#include <iostream>

#include "cstring.h"

using namespace std;

namespace sdds {

void Bill::setEmpty() {
    m_title[0] = '\0';
    m_items = nullptr;
}

bool Bill::isValid() const {
    return (m_title[0] != '\0' || m_items != nullptr);
}

double Bill::totalTax() const {
    int i;
    double sum = 0.0;
    for (i = 0; i < m_noOfItems; i++) {
        sum += m_items[i].tax();
    }
    return sum;
}

double Bill::totalPrice() const {
    int i;
    double totalPrice = 0.0;
    for (i = 0; i < m_noOfItems; i++) {
        totalPrice += m_items[i].price();
    }
    return totalPrice;
}

void Bill::Title() const {
    cout << "+--------------------------------------+" << endl;
    if (isValid()) {
        cout << "| " << left << setw(36) << m_title << " |" << endl;
    } else {
        cout << "| Invalid Bill                         |" << endl;
    }
    cout << "+----------------------+---------+-----+" << endl;
    cout << "| Item Name            | Price   + Tax |" << endl;
    cout << "+----------------------+---------+-----+" << endl;
}

void Bill::footer() const {
    cout << "+----------------------+---------+-----+" << endl;
    if (isValid()) {
        cout << "|                Total Tax: " << setw(10) << fixed << setprecision(2) << totalTax() << " |" << endl;
        cout << "|              Total Price: " << setw(10) << fixed << setprecision(2) << totalPrice() << " |" << endl;
        cout << "|          Total After Tax: " << setw(10) << fixed << setprecision(2) << totalPrice() + totalTax() << " |" << endl;
    } else {
        cout << "| Invalid Bill                         |" << endl;
    }
    cout << "+--------------------------------------+" << endl;
}

void Bill::init(const char* title, int noOfItems) {
    if (title == nullptr || noOfItems <= 0) {
        setEmpty();
    } else {
        m_noOfItems = noOfItems;
        m_itemsAdded = 0;
        strnCpy(m_title, title, 36);
        m_items = new Item[noOfItems];
        int i;
        for (i = 0; i < noOfItems; i++) {
            m_items[i].setEmpty();
        }
    }
}

bool Bill::add(const char* item_name, double price, bool taxed) {
    if (m_itemsAdded < m_noOfItems) {
        m_items[m_itemsAdded].set(item_name, price, taxed);
        m_itemsAdded++;
        return true;
    } else {
        return false;
    }
}

void Bill::display() const {
    Title();
    int i = 0;
    for (i = 0; i < m_itemsAdded; i++) {
        m_items[i].display();
    }
    footer();
}

void Bill::deallocate() {
    delete[] m_items;
    m_items = nullptr;
}
}  // namespace sdds