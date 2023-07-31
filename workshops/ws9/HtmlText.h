/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
Date: July 30, 2023
*/
#ifndef SDDS_HTMLTEXT_H__
#define SDDS_HTMLTEXT_H__
#include "Text.h"
namespace sdds {
class HtmlText : public Text {
    char* m_title;

   public:
    HtmlText(const char* filename = nullptr, const char* title = nullptr);
    // rule of three
    HtmlText(const HtmlText& htmlObject);
    HtmlText& operator=(HtmlText& htmlObject);
    virtual ~HtmlText();

    void write(std::ostream& os) const;
};
}  // namespace sdds
#endif  // !SDDS_HTMLTEXT_H__