#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H
#include <iostream>

#include "Shape.h"
namespace sdds {
class LblShape : public Shape {
   private:
    char* m_label{};
    LblShape(const LblShape&) = delete;
    LblShape& operator=(const LblShape&) = delete;

   protected:
    const char* label() const;

   public:
    LblShape();
    LblShape(const char* labelName);
    virtual ~LblShape();
    void getSpecs(std::istream& is);
};
}  // namespace sdds
#endif  // SDDS_LBLSHAPE_H