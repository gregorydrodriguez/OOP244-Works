#include "Shape.h"

#include <iostream>
#include <string>

using namespace std;
namespace sdds {
ostream& operator<<(ostream& os, const Shape& shape) {
    shape.draw(os);
    return os;
}
istream& operator>>(istream& is, Shape& shape) {
    shape.getSpecs(is);
    return is;
}
}  // namespace sdds