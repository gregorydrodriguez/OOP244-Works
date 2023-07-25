#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H
#include <iostream>

#include "LblShape.h"

namespace sdds {
class Rectangle : public LblShape {
   private:
    int m_width;
    int m_height;

   public:
    Rectangle();
    Rectangle(const char* labelName, int width, int height);
    void getSpecs(std::istream& is);
    void draw(std::ostream& os) const;
};
}  // namespace sdds
#endif  // SDDS_RECTANGLE_H