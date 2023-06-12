#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H
#include <iostream>

namespace sdds {
class Label {
    char* m_frame;
    char* m_content;
    void setFrame(const char* frameArg);
    void setContent(const char* content);
    void setDefault();

   public:
    Label();
    Label(const char* frameArg);
    Label(const char* frameArg, const char* content);
    ~Label();
    void readLabel();
    std::ostream& printLabel() const;
};

}  // namespace sdds
#endif  // SDDS_LABEL_H