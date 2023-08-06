/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Book.h"
#include "Menu.h"
#include "Publication.h"
namespace sdds {
class LibApp {
   private:
    // MS5
    char m_filename[256];
    Publication* m_publications[SDDS_LIBRARY_CAPACITY] = {};
    int m_numOfLoadedPubs;
    int m_lastLibRefNum;
    Menu* m_pubTypeMenu;
    // Original
    bool m_changed;
    Menu* m_mainMenu;
    Menu* m_exitMenu;
    bool confirm(const char* message);
    LibApp(const LibApp&) = delete;
    LibApp& operator=(const LibApp&) = delete;

   public:
    // MS5 additional methods
    Publication* getPub(int libRef);

    LibApp(const char* filename);
    ~LibApp();
    void load();
    void save();
    void search();
    int search(int searchMode);
    void returnPub();
    void newPublication();
    void removePublication();
    void checkOutPub();
    void run();
};
}  // namespace sdds
#endif  // SDDS_LIBAPP_H