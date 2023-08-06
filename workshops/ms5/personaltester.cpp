#include <iostream>

#include "Publication.h"
#include "Utils.h"
using namespace std;
using namespace sdds;

int main() {
  Publication p;
  cout << p.checkoutDate() << endl;
  p.resetDate();
  cout << p.checkoutDate() << endl;
}