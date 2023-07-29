#include "Streamable.h"

using namespace std;
namespace sdds {
std::ostream& operator<<(std::ostream& os, const Streamable& stream) {
    if (stream) {
        stream.write(os);
    }
    return os;
}

std::istream& operator>>(std::istream& is, Streamable& stream) {
    return stream.read(is);
}
}  // namespace sdds