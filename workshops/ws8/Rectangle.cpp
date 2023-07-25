#include "Rectangle.h"

#include <iomanip>
#include <string>
#include <cstring>

using namespace std;
namespace sdds {
Rectangle::Rectangle() : LblShape() {
    m_width = 0;
    m_height = 0;
}

Rectangle::Rectangle(const char* labelName, int width, int height) : LblShape(labelName) {
    m_width = width;
    m_height = height;
    int temp = strlen(label() + 2);
    if (m_height < 3 || m_width < temp) {
        m_height = 0;
        m_width = 0;
    }
}

void Rectangle::getSpecs(istream& is) {
    LblShape::getSpecs(is);
    is >> m_width;
    is.ignore();
    is >> m_height;
    is.ignore(1000, '\n');
}

void Rectangle::draw(ostream& os) const {
    if (m_height > 0 && m_width > 0) {
        os << "+";
        for (int i = 0; i < m_width - 2; i++) {
            os << '-';
        }
        os << '+' << endl;

        os << '|' << setw(m_width - 2) << left << LblShape::label() << '|' << endl;

        for (int i = 0; i < m_height - 3; i++) {
            os << '|';
            for (int j = 0; j < m_width - 2; j++) {
                os << " ";
            }
            os << '|' << endl;
        }
        os << "+";
        for (int i = 0; i < m_width - 2; i++) {
            os << '-';
        }
        os << "+";
    }
}

}  // namespace sdds