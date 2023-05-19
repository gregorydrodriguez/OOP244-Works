#ifndef SDDS_SHOPPINGLIST_H
#define SDDS_SHOPPINGLIST_H
#include "ShoppingRec.h"

namespace sdds {
bool loadList();
void displayList();
void removeBoughtItems();
void removeItem(int index);
bool saveList();
void clearList();
void toggleBought();
void addItemToList();
void removeItemfromList();
bool listIsEmpty();

}  // namespace sdds
#endif