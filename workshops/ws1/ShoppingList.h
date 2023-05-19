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


    const int MAX_NO_OF_RECS = 15;
    ShoppingRec recs[MAX_NO_OF_RECS] = {};
    int noOfRecs = 0;

} // namespace sdds
#endif