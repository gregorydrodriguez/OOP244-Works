/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#include "Streamable.h"

using namespace std;
namespace sdds {
std::ostream& operator<<(std::ostream& os, const Streamable& stream) {
    if (stream) {
        stream.write(os);
    } else {
        cout << "stream invalid" << endl;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Streamable& stream) {
    return stream.read(is);
}
}  // namespace sdds