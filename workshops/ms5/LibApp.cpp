/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student #: 127880227
*/
#include "LibApp.h"

#include <fstream>
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <cstring>

#include "Menu.h"
#include "PublicationSelector.h"

using namespace std;
namespace sdds {
LibApp::LibApp(const char* filename) {
    // MS5
    m_numOfLoadedPubs = 0;
    m_lastLibRefNum = 0;
    m_pubTypeMenu = new Menu("Choose the type of publication:");
    *m_pubTypeMenu << "Book"
                   << "Publication";
    strcpy(m_filename, filename);
    // Original
    m_changed = false;
    m_mainMenu = new Menu("Seneca Library Application");
    *m_mainMenu << "Add New Publication"
                << "Remove Publication"
                << "Checkout publication from library"
                << "Return publication to library";
    m_exitMenu = new Menu("Changes have been made to the data, what would you like to do?");
    *m_exitMenu << "Save changes and exit"
                << "Cancel and go back to the main menu";
    load();
}

LibApp::~LibApp() {
    delete m_mainMenu;
    delete m_exitMenu;
    delete m_pubTypeMenu;
}

bool LibApp::confirm(const char* message) {
    Menu* confirmMenu = new Menu(message);
    *confirmMenu << "Yes";
    if (confirmMenu->run() == 1) {
        delete confirmMenu;
        return true;
    }
    delete confirmMenu;
    return false;
}

// MS5 Modification
void LibApp::load() {
    cout << "Loading Data" << endl;
    ifstream iFile(m_filename);
    char type{};
    while (iFile >> type) {
        if (type == 'P') {
            m_publications[m_numOfLoadedPubs] = new Publication();
            m_publications[m_numOfLoadedPubs]->read(iFile);
            m_lastLibRefNum = m_publications[m_numOfLoadedPubs]->getRef();
            m_numOfLoadedPubs++;
        } else if (type == 'B') {
            m_publications[m_numOfLoadedPubs] = new Book();
            m_publications[m_numOfLoadedPubs]->read(iFile);
            m_lastLibRefNum = m_publications[m_numOfLoadedPubs]->getRef();
            m_numOfLoadedPubs++;
        }
    }
}

// MS5 Modification
void LibApp::save() {
    cout << "Saving Data" << endl;
    ofstream iFile(m_filename);
    for (int i = 0; i < m_numOfLoadedPubs; i++) {
        if (m_publications[i]->getRef() != 0) {
            iFile << *m_publications[i];
        }
    }
}

void LibApp::search() {
    cout << "Searching for publication" << endl;
}

// MS5 Modification
int LibApp::search(int searchMode) {
    cout << "Searching for publication" << endl;
    int selection = m_pubTypeMenu->run();
    if (selection == 0) {
        cout << "Aborted!" << endl;
        return selection;
    }
    cout << "Publication Title: ";
    char title[256];
    cin >> title;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    PublicationSelector pubSelector;
    bool matchesFound = false;
    for (int i = 0; i < m_numOfLoadedPubs; i++) {
        if (searchMode == 1) {  // Search all publications
            if ((const char*)(m_publications[i]) == title) {
                pubSelector << *m_publications[i];
                matchesFound = true;
            }
        } else if (searchMode == 2) {  // Search checked out publications
            if (m_publications[i]->onLoan() &&
                (const char*)(m_publications[i]) == title) {
                pubSelector << *m_publications[i];
                matchesFound = true;
            }
        } else if (searchMode == 3) {  // Search available publications
            if (!m_publications[i]->onLoan() &&
                (const char*)(m_publications[i]) == title) {
                pubSelector << *m_publications[i];
                matchesFound = true;
            }
        }
    }
    if (matchesFound) {
        pubSelector.sort();
        selection = pubSelector.run();
        if (selection == 0) {
            cout << "Aborted!" << endl;
        }
    } else {
        cout << "No matches found!" << endl;
    }
    return selection;
}

// MS5 Modification
Publication* LibApp::getPub(int libRef) {
    return m_publications[libRef];
}

// MS5 Modification
void LibApp::returnPub() {
    cout << "Return publication to the library" << endl;
    int selection = search(2);
    if (confirm("Return Publication?")) {
        Date currentDate = Date();
        int daysLoaned = currentDate - m_publications[selection]->checkoutDate();
        if (daysLoaned > 15) {
            double lateFee = (double)(daysLoaned - 15) * 0.50;
            cout << "Please pay $";
            cout << fixed << setprecision(2) << lateFee;
            cout << " penalty for being ";
            cout << daysLoaned << " days late!" << endl;
        }
        m_publications[selection]->set(0);
        m_changed = true;
        cout << "Publication returned" << endl;
    }
    cout << endl;
}

// MS5 Modification
void LibApp::newPublication() {
    if (m_numOfLoadedPubs == SDDS_LIBRARY_CAPACITY) {
        cout << "Library is at its maximum capacity!";
        return;
    }
    cout << "Adding new publication to the library" << endl;
    int selection = m_pubTypeMenu->run();
    Publication* addition;
    if (selection == 1) {
        addition = new Book();
        addition->read(cin);
    } else if (selection == 2) {
        addition = new Publication();
        addition->read(cin);
    }
    if (!cin.good()) {
        cout << "Aborted!" << endl;
        return;
    } else {
        if (confirm("Add this publication to the library?")) {
            if (bool(addition)) {
                m_lastLibRefNum++;
                addition->setRef(m_lastLibRefNum);
                m_publications[m_numOfLoadedPubs] = addition;
                m_numOfLoadedPubs++;
                m_changed = true;
                cout << "Publication added" << endl;
            } else {
                cout << "Failed to add publication!";
                delete addition;
            }
        } else {
            cout << "Aborted!" << endl;
            return;
        }
    }
    cout << endl;
}

// MS5 Modification
void LibApp::removePublication() {
    cout << "Removing publication from library" << endl;
    int selection = search(1);
    if (confirm("Remove this publication from the library?")) {
        m_changed = true;
        m_publications[selection]->setRef(0);
        cout << "Publication removed" << endl;
    }
    cout << endl;
}

// MS5 Modification
void LibApp::checkOutPub() {
    cout << "Checkout publication from the library";
    int selection = search(3);
    if (confirm("Check out publication?")) {
        int membershipNum;
        cout << "Enter Membership number: ";
        do {
            cin >> membershipNum;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (membershipNum < 9999 || membershipNum > 99999) {
                cout << "Invalid membership number, try again: ";
            }
        } while (membershipNum < 9999 || membershipNum > 99999);
        m_publications[selection]->set(membershipNum);
        m_changed = true;
        cout << "Publication checked out" << endl;
    }
    cout << endl;
}

// MS5 Modification
void LibApp::run() {
    bool done = false;
    unsigned int selection = 1;
    while (!done) {
        m_mainMenu->displayTitle();
        m_mainMenu->displayMenu();
        cout << "> ";
        cin.clear();
        cin >> selection;
        if (selection == 1) {
            newPublication();
        }
        if (selection == 2) {
            removePublication();
        }
        if (selection == 3) {
            checkOutPub();
        }
        if (selection == 4) {
            returnPub();
        }
        if (selection == 0) {
            if (m_changed == true) {
                selection = m_exitMenu->run();
                if (selection == 1) {
                    save();
                    done = true;
                } else if (selection == 0) {
                    if (confirm("This will discard all the changes are you sure?")) {
                        done = true;
                    }
                } else {
                    cout << endl;
                }
            } else {
                done = true;
            }
        }
    }
    cout << endl;
    cout << "-------------------------------------------" << endl;
    cout << "Thanks for using Seneca Library Application" << endl;
}
}  // namespace sdds