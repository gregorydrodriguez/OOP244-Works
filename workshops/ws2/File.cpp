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
// TODO: read functions go here
bool read(char m_name[]) {
    return fscanf(fptr, "%[^\n]\n", m_name) == 1;
}
bool read(int& m_empNo) {
    return fscanf(fptr, "%d,", &m_empNo) == 1;
}
bool read(double& m_salary) {
    return fscanf(fptr, "%lf,", &m_salary) == 1;
}
}  // namespace sdds