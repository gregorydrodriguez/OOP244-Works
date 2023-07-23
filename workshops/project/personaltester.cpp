#include <iostream>

#include "Menu.h"
#include "LibApp.h"
#include "Utils.h"
using namespace std;
using namespace sdds;

int main() {
    LibApp libApp = LibApp();
    // libApp.confirm("Test");
    // libApp.returnPub();
    // libApp.newPublication();
    libApp.run();
}