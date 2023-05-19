#ifndef SDDS_FILE_H
#define SDDS_FILE_H
#include <cstdio>

#include "ShoppingRec.h"

namespace sdds {

bool openFileForRead();
bool openFileForOverwrite();
void closeFile();
bool freadShoppingRec(ShoppingRec* rec);
void fwriteShoppintRec(const ShoppingRec* rec);

}  // namespace sdds
#endif