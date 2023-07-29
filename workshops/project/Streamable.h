#ifndef SDDS_STREAMABLE_H
#define SDDS_STREAMABLE_H
#include <iostream>
namespace sdds {
class Streamable {
   public:
    virtual std::ostream& write(std::ostream& os) const = 0;
    virtual std::istream& read(std::istream& is) = 0;
    virtual bool conIO(std::ios& stream) const = 0;
    virtual operator bool() const = 0;
    virtual ~Streamable(){};
};
std::ostream& operator<<(std::ostream& os, const Streamable& stream);
std::istream& operator>>(std::istream& is, Streamable& stream);

}  // namespace sdds
#endif  // SDDS_STREAMABLE_H