/*
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student ID: 127880227
Workshop 1
w1p1.cpp
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include "cstring.h"

namespace sdds {
void strCpy(char* des, const char* src) {
    int i;
    for (i = 0; i < strLen(src); i++) {
        des[i] = src[i];
    }
    des[i] = '\0';
}

void strnCpy(char* des, const char* src, int len) {
    int i;
    for (i = 0; i < len; i++) {
        des[i] = src[i];
    }
    if (strLen(src) < len) {
        des[i] = '\0';
    }
}

int strCmp(const char* s1, const char* s2) {
    int len;

    if (strLen(s1) > strLen(s2)) {
        len = strLen(s1);
    } else {
        len = strLen(s2);
    }

    for (int i = 0; i < len; i++) {
        if (s1[i] > s2[i]) {
            return 1;
        }
        if (s1[i] < s2[i]) {
            return -1;
        }
    }
    return 0;
}

int strnCmp(const char* s1, const char* s2, int len) {
    for (int i = 0; i < len; i++) {
        if (s1[i] > s2[i]) {
            return 1;
        }
        if (s1[i] < s2[i]) {
            return -1;
        }
    }
    return 0;
}

int strLen(const char* s) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

// strStr("abcdefghijklmnopqrstuvwxyz", "jkl")
// Expected output: jklmnopqrstuvwxyz
const char* strStr(const char* str1, const char* str2) {
    if (strLen(str2) > strLen(str1)) {
        return nullptr;
    }
    
    // check if str2 exists at each index of str1
    int str1Index = 0;
    while (str1[str1Index] != '\0') {
        int found = 1;
        for (int i = 0; i < strLen(str2); i++) {
            if (str1[str1Index + i] != str2[i]) {
                // str2 does not exist at this str1 index
                found = 0;
                break;
            }
        }
        if (found) {
            return &str1[str1Index];
        }
        str1Index++;
    }
    return nullptr;
}

void strCat(char* des, const char* src) {
    int j = strLen(des);
    for (int i = 0; i < strLen(src); i++) {
        des[j] = src[i];
        j++;
    }
    des[j] = '\0';
}

}  // namespace sdds