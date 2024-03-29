/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"
namespace sdds {
class LibApp {
   private:
    bool m_changed;
    Menu* m_mainMenu;
    Menu* m_exitMenu;
    bool confirm(const char* message);
    LibApp(const LibApp&) = delete;
    LibApp& operator=(const LibApp&) = delete;


   public:
    LibApp();
    ~LibApp();
    void load();
    void save();
    void search();
    void returnPub();
    void newPublication();
    void removePublication();
    void checkOutPub();
    void run();
};
}  // namespace sdds
#endif  // SDDS_LIBAPP_H