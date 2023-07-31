#include "Text.h"

#include <iostream>

using namespace std;
using namespace sdds;

int main(void) {
    Text T("test.txt");
    Text Y("whatever.txt");  // whatever.txt can exist or not
    Text Z;
    Y = T;
    Z = Y;
    Text X = Z;
    cout << X << endl;

    return 0;
}
