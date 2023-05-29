#define _CRT_SECURE_NO_WARNINGS
#include "File.h"

#include <cstdio>

namespace sdds {
FILE* fptr;
bool openFile(const char filename[]) {
    fptr = fopen(filename, "r");
    return fptr != NULL;
}
int noOfRecords() {
    int noOfRecs = 0;
    char ch;
    while (fscanf(fptr, "%c", &ch) == 1) {
        noOfRecs += (ch == '\n');
    }
    rewind(fptr);
    return noOfRecs;
}
void closeFile() {
    if (fptr) fclose(fptr);
}
bool read(char pCode[]) {
    return fscanf(fptr, "%[^,],", pCode) == 1;
}
bool read(int& pop) {
    return fscanf(fptr, "%d\n", &pop) == 1;
}
}  // namespace sdds