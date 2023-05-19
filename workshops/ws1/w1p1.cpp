/*
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student ID: 127880227
Workshop 1
w1p1.cpp
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <cstdlib>

// set to false when compiling on Linux
const bool APP_OS_WINDOWS = false;

using namespace std;



void flushkeys();
bool ValidYesResponse(char ch);
bool yes();
void readCstr(char cstr[], int len);
int readInt(int min, int max);


const char* const SHOPPING_DATA_FILE = "shoppinglist.csv";
FILE* sfptr = nullptr;



const int MAX_TITLE_LENGTH = 50;
const int MAX_QUANTITY_VALUE = 50;
struct ShoppingRec {
   char m_title[MAX_TITLE_LENGTH + 1];
   int m_quantity;
   bool m_bought;
};

const int MAX_NO_OF_RECS = 15;
ShoppingRec recs[MAX_NO_OF_RECS] = {};
int noOfRecs = 0;


ShoppingRec getShoppingRec();
void displayShoppingRec(const ShoppingRec* shp);
void toggleBoughtFlag(ShoppingRec* rec);
bool isShoppingRecEmpty(const ShoppingRec* shp);

bool openFileForRead();
bool openFileForOverwrite();
void closeFile();
bool freadShoppingRec(ShoppingRec* rec);
void fwriteShoppintRec(const ShoppingRec* rec);

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

int listMenu();

// shoppingListApp.cpp
// int main() {
//    bool done = false;
//    loadList();
//    while (!done) {
//       system(APP_OS_WINDOWS ? "cls" : "clear");
//       switch (listMenu()) {
//       case 1:
//          toggleBought();
//          break;
//       case 2:
//          addItemToList();
//          break;
//       case 3:
//          removeItemfromList();
//          break;
//       case 4:
//          removeBoughtItems();
//          break;
//       case 5:
//          clearList();
//          break;
//       default:
//          done = true;
//       }
//    }
//    saveList();
//    return 0;
// }

// shoppingListApp.cpp
// int listMenu() {
//    cout << "-->>> My Shopping List <<<--" << endl;
//    displayList();
//    cout << "----------------------------" << endl
//       << "1- Toggle bought Item" << endl
//       << "2- Add Shopping Item" << endl
//       << "3- Remove Shopping Item" << endl
//       << "4- Remove bought Items" << endl
//       << "5- Clear List" << endl
//       << "0- Exit" << endl << "> ";
//    return readInt(0, 5);
// }

// void flushkeys() {
//    while (cin.get() != '\n');
// }

// bool ValidYesResponse(char ch) {
//    return ch == 'Y' || ch == 'y' || ch == 'N' || ch == 'n';
// }

// bool yes() {
//    char ch = 0;
//    do {
//       cin >> ch;
//       flushkeys();
//    } while (!ValidYesResponse(ch) && cout << "Only (Y/y) or (N/n) is acceptable: ");
//    return ch == 'y' || ch == 'Y';
// }

// void readCstr(char cstr[], int len) {
//    char buf[1024] = {};
//    int i;
//    cin.getline(buf, 1024);
//    for (i = 0; i < len && buf[i]; i++) {
//       cstr[i] = buf[i];
//    }
//    cstr[i] = 0;
// }

// int readInt(int min, int max) {
//    int value = 0;
//    bool done = false;
//    while (!done) {
//       cin >> value;
//       if (!cin) {
//          cin.clear();
//          cout << "Bad integer, try agian: ";
//       }
//       else {
//          if (value >= min && value <= max) {
//             done = true;
//          }
//          else {
//             cout << "Value out of range (" << min << "<=value<=" << max << "): ";
//          }
//       }
//       flushkeys();
//    }
//    return value;
// }


// ShoppingRec getShoppingRec() {
//    ShoppingRec R = {};
//    cout << "Item name: ";
//    readCstr(R.m_title, MAX_TITLE_LENGTH);
//    cout << "Quantity: ";
//    R.m_quantity = readInt(1, MAX_QUANTITY_VALUE);
//    return R;
// }
// void displayShoppingRec(const ShoppingRec* shp) {
//    cout << "[" << (shp->m_bought ? 'X' : ' ') << "]" << shp->m_title <<
//       " qty:(" << shp->m_quantity << ")" << endl;
// }
// void toggleBoughtFlag(ShoppingRec* rec) {
//    rec->m_bought = !rec->m_bought;

// }
// bool isShoppingRecEmpty(const ShoppingRec* shp) {
//    return shp->m_title[0] == 0;
// }




// bool loadList() {
//    ShoppingRec shpr = {};
//    bool ok = false;
//    if (openFileForRead()) {
//       ok = true;
//       while (noOfRecs < MAX_NO_OF_RECS &&
//          freadShoppingRec(&shpr)) {
//          recs[noOfRecs++] = shpr;
//       }
//       closeFile();
//    }
//    return ok;
// }
// bool saveList() {
//    bool ok = false;
//    if (openFileForOverwrite()) {
//       ok = true;
//       for (int i = 0; i < noOfRecs; i++) {
//          fwriteShoppintRec(&recs[i]);
//       }
//       closeFile();
//    }
//    return ok;
// }

// void removeItem(int index) {
//    if (index >= 0 && index < noOfRecs) {
//       noOfRecs--;
//       for (int i = index; i < noOfRecs; i++) {
//          recs[i] = recs[i + 1];
//       }
//    }
// }
// void clearList() {
//    cout << "This will remove all the items from the list;" << endl
//       << "Are you sure? (Y)es/(N)o" << endl;
//    if (yes()) {
//       noOfRecs = 0;
//    }
//    else {
//       cout << "Cancelled!" << endl;
//    }
// }
// void toggleBought() {
//    cout << "Item number: ";
//    toggleBoughtFlag(&recs[readInt(1, noOfRecs) - 1]);
// }

// void addItemToList() {
//    if (noOfRecs < MAX_NO_OF_RECS) {
//       recs[noOfRecs] = getShoppingRec();
//       noOfRecs += !isShoppingRecEmpty(&recs[noOfRecs]);
//    }
//    else {
//       cout << "Shopping List is full!" << endl;
//    }
// }

// void removeItemfromList() {
//    if (!listIsEmpty()) {
//       int value = 0;
//       cout << "Item number to delete: ";
//       value = readInt(1, noOfRecs);
//       cout << "Deleting following item, are you sure?" << endl;
//       displayShoppingRec(&recs[value - 1]);
//       cout << "(Y)es/(N)o: ";
//       if (yes()) {
//          removeItem(value - 1);
//       }
//       else {
//          cout << "Cancelled!" << endl;
//       }
//    }
//    else {
//       cout << "List is empty!" << endl;
//    }

// }

// bool listIsEmpty() {
//    return noOfRecs == 0;
// }



// void displayList() {
//    for (int i = 0; i < noOfRecs; i++) {
//       cout << (i + 1) << "-";
//       displayShoppingRec(&recs[i]);
//    }
// }

// void removeBoughtItems() {
//    if (!listIsEmpty()) {
//       cout << "Removing bought items, are you sure?" << endl;
//       cout << "(Y)es/(N)o: ";
//       if (yes()) {
//          for (int i = 0; i < noOfRecs; i++) {
//             if (recs[i].m_bought) removeItem(i--);
//          }
//       }
//       else {
//          cout << "Cancelled!" << endl;
//       }
//    }
//    else {
//       cout << "List is empty!" << endl;
//    }
// }



// bool openFileForRead() {
//    sfptr = fopen(SHOPPING_DATA_FILE, "r");
//    return sfptr != NULL;
// }

// bool openFileForOverwrite() {
//    sfptr = fopen(SHOPPING_DATA_FILE, "w");
//    return sfptr != NULL;
// }

// void closeFile() {
//    if (sfptr) fclose(sfptr);
// }

// bool freadShoppingRec(ShoppingRec* rec) {
//    int flag = 0;
//    bool success = fscanf(sfptr, "%[^,],%d,%d\n",
//       rec->m_title, &rec->m_quantity, &flag) == 3;
//    rec->m_bought = !!flag;
//    return success;
// }

// void fwriteShoppintRec(const ShoppingRec* rec) {
//    fprintf(sfptr, "%s,%d,%d\n", rec->m_title, rec->m_quantity, rec->m_bought);
// }