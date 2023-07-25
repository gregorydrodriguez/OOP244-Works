#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include "LblShape.h"
namespace sdds {
class Line : public LblShape {
   private:
    int m_length;

   public:
    Line();
    Line(const char* labelName, int length);
    void getSpecs(std::istream& is);
    void draw(std::ostream& os) const;
};
}  // namespace sdds
#endif  // SDDS_LINE_H