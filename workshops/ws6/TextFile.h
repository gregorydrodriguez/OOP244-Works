/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#ifndef SDDS_TEXTFILE_H__
#define SDDS_TEXTFILE_H__
#include <iostream>
namespace sdds {
class Line {
    char* m_value{nullptr};
    operator const char*() const;
    Line(){};
    Line& operator=(const char*);
    ~Line();
    friend class TextFile;
    // copy and copy assignment prevention goes here
    Line(const Line& obj) = delete;
    Line& operator=(const Line& obj) = delete;
};

class TextFile {
    Line* m_textLines{};
    char* m_filename{};      // initialized to nullptr
    unsigned m_noOfLines{};  // initialized to default
    unsigned m_pageSize;
    void setFilename(const char* fname, bool isCopy = false);
    void setNoOfLines();
    void loadText();
    void saveAs(const char* fileName) const;
    void setEmpty();

   public:
    TextFile(unsigned pageSize = 15);
    TextFile(const char* filename, unsigned pageSize = 15);
    TextFile(const TextFile&);
    TextFile& operator=(const TextFile&);
    ~TextFile();
    std::ostream& view(std::ostream& ostr) const;
    std::istream& getFile(std::istream& istr);
    operator bool() const;
    unsigned lines() const;
    const char* name() const;
    const char* operator[](unsigned index) const;
};
std::ostream& operator<<(std::ostream& ostr, const TextFile& text);
std::istream& operator>>(std::istream& istr, TextFile& text);

}  // namespace sdds
#endif  // !SDDS_TEXTFILE_H__