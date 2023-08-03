/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__
#include <iostream>

namespace sdds {
const unsigned int MAX_MENU_ITEMS = 20;

class MenuItem {
   private:
    friend class Menu;
    char* m_itemName;
    MenuItem();
    MenuItem(const char* itemName);
    MenuItem(const MenuItem&) = delete;
    MenuItem& operator=(const MenuItem&) = delete;
    virtual ~MenuItem();
    operator bool() const;
    operator const char*() const;
};

class Menu {
   private:
    MenuItem* m_menuTitle{};
    MenuItem* m_menuItems[MAX_MENU_ITEMS]{};
    unsigned int m_numOfItems;
    Menu(const Menu&) = delete;
    Menu& operator=(const Menu&) = delete;

   public:
    Menu();
    Menu(const char* srcTitle);
    virtual ~Menu();
    unsigned int run() const;
    std::ostream& displayMenu() const;
    std::ostream& displayTitle() const;
    const char* getMenuTitle() const;
    Menu& operator<<(const char* menuItemContent);
    const char* operator[](unsigned int index) const;
    operator int() const;
    operator unsigned int() const;
    operator bool() const;
    unsigned int operator~() const;
};

std::ostream& operator<<(std::ostream& ostr, const Menu& menu);
}  // namespace sdds
#endif