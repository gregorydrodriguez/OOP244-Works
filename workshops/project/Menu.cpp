/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"

#include <cstring>
#include <iomanip>
#include <iostream>
#include <limits>

using namespace std;
namespace sdds {
// Menu Class
ostream& operator<<(ostream& ostr, const Menu& menu) {
    ostr << menu.getMenuTitle();
    return ostr;
}

const char* Menu::operator[](unsigned int index) const {
    return (const char*)(*m_menuItems[index]);
}

const char* Menu::getMenuTitle() const {
    return m_menuTitle->m_itemName ? m_menuTitle->m_itemName : "";
}

Menu::operator bool() const {
    return m_numOfItems;
}

Menu::operator int() const {
    return m_numOfItems;
}

Menu::operator unsigned int() const {
    return m_numOfItems;
}

Menu& Menu::operator<<(const char* menuItemContent) {
    if (m_numOfItems < MAX_MENU_ITEMS) {
        m_menuItems[m_numOfItems] = new MenuItem(menuItemContent);
        m_numOfItems++;
    }
    return *this;
}

unsigned int Menu::operator~() const {
    return run();
}

unsigned int Menu::run() const {
    unsigned int selection = 1;
    displayTitle();
    displayMenu();
    cout << "> ";
    do {
        cin.clear();
        cin >> selection;
        if (cin.fail() || selection > m_numOfItems) {
            cout << "Invalid Selection, try again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return selection;
        }
    } while (true);
}

ostream& Menu::displayMenu() const {
    for (unsigned int i = 0; i < m_numOfItems; i++) {
        cout << setw(2) << right << i + 1 << "- " << m_menuItems[i]->m_itemName << endl;
    }
    cout << setw(4) << right << "0- "
         << "Exit" << endl;
    return cout;
}

ostream& Menu::displayTitle() const {
    const char* title = getMenuTitle();
    if (title[0] != '\0') {
        cout << title << endl;
    }
    return cout;
}

Menu::Menu() {
    cout << "default" << endl;
    m_menuTitle = new MenuItem();
    m_numOfItems = 0;
}

Menu::Menu(const char* srcTitle) {
    m_menuTitle = new MenuItem(srcTitle);
    m_numOfItems = 0;
}

Menu::~Menu() {
    for (unsigned int i = 0; i < MAX_MENU_ITEMS; i++) {
        delete m_menuItems[i];
    }
    delete m_menuTitle;
}

// MenuItem Class
MenuItem::MenuItem() {
    m_itemName = nullptr;
}

MenuItem::MenuItem(const char* itemName) {
    m_itemName = new char[strlen(itemName) + 1];
    strcpy(m_itemName, itemName);
}

MenuItem::~MenuItem() {
    delete[] m_itemName;
}

MenuItem::operator bool() const {
    return m_itemName;
}

MenuItem::operator const char*() const {
    return m_itemName;
}
}  // namespace sdds