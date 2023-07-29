#ifndef SDDS_PUBLICATION_H
#define SDDS_PUBLICATION_H
#include "Date.h"
#include "Lib.h"
#include "Streamable.h"
namespace sdds {
class Publication : public Streamable {
   private:
    char* m_title;
    char m_shelfID[SDDS_SHELF_ID_LEN + 1];
    int m_membership;
    int m_libRef;
    Date m_date;

   public:
    Publication();
    virtual void set(int member_id);
    void setRef(int value);
    void resetDate();
    virtual char type() const;
    bool onLoan() const;
    Date checkoutDate() const;
    bool operator==(const char* title) const;
    operator const char*() const;
    int getRef() const;
    bool conIO(std::ios& io) const;
    std::ostream& write(std::ostream& os) const;
    std::istream& read(std::istream& istr);
    operator bool() const;

    // Rule of 3
    Publication(const Publication& object);
    Publication& operator=(const Publication& object);
    ~Publication();
    
};
}  // namespace sdds
#endif  // SDDS_PUBLICATION_H