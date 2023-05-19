#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
namespace sdds {
    void flushkeys();
    bool ValidYesResponse(char ch);
    bool yes();
    void readCstr(char cstr[], int len);
    int readInt(int min, int max);
} // namespace sdds
#endif