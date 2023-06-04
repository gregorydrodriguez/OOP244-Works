#include "Item.h"

#include <iomanip>
#include <iostream>

#include "cstring.h"

using namespace std;

namespace sdds {
const double TAX = 0.13;

void Item::setName(const char* name) {
    strncpy(m_itemName, name, 20);
}

void Item::setEmpty() {
    m_price = 0.0;
    m_itemName[0] = '\0';
}

void Item::set(const char* name, double price, bool taxed) {
    if (price < 0.0 || name == nullptr) {
        setEmpty();
    } else {
        setName(name);
        m_price = price;
        m_taxed = taxed;
    }
}

double Item::price() const {
    return m_price;
}

double Item::tax() const {
    return m_taxed == 1 ? m_price * TAX : 0.0;
}

bool Item::isValid() const {
    return (m_price != 0.0 || m_itemName[0] != '\0');
}

void Item::display() const {
    if (isValid()) {
        cout << "| ";
        cout << left << setw(20) << setfill('.') << m_itemName << " | ";
        cout << right << setw(7) << git m_price << " | ";
        cout << (m_taxed ? "Yes" : "No ") << " |" << endl;
    } else {
        cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
    }
}

}  // namespace sdds
