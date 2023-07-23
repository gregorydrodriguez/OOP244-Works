#include "LibApp.h"

#include "Menu.h"

using namespace std;
namespace sdds {
LibApp::LibApp() {
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

void LibApp::load() {
    cout << "Loading Data" << endl;
}

void LibApp::save() {
    cout << "Saving Data" << endl;
}

void LibApp::search() {
    cout << "Searching for publication" << endl;
}

void LibApp::returnPub() {
    search();
    cout << "Returning publication" << endl;
    cout << "Publication returned" << endl;
    m_changed = true;
    cout << endl;
}

void LibApp::newPublication() {
    cout << "Adding new publication to library" << endl;
    if (confirm("Add this publication to library?")) {
        m_changed = true;
        cout << "Publication added" << endl;
    }
    cout << endl;
}

void LibApp::removePublication() {
    cout << "Removing publication from library" << endl;
    search();
    if (confirm("Remove this publication from the library?")) {
        m_changed = true;
        cout << "Publication removed" << endl;
    }
    cout << endl;
}

void LibApp::checkOutPub() {
    search();
    if (confirm("Check out publication?")) {
        m_changed = true;
        cout << "Publication checked out" << endl;
    }
    cout << endl;
}

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
    // do {
    //     cin.clear();
    //     cin >> selection;
    //     if (cin.fail() || selection > 4) {
    //         cout << "Invalid Selection, try again: ";
    //         cin.clear();
    //         cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //     } else {
    //         cin.clear();
    //         cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //         return selection;
    //     }
    // } while (true);
}
}  // namespace sdds