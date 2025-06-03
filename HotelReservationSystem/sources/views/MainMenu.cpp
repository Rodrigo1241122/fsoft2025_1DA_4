#include "MainMenu.h"
#include <iostream>
#include <string>

using namespace std;

void MainMenu::display_main_menu() {
    cout << "\n" << string(40, '=') << endl;
    cout << "     HOTEL MANAGEMENT SYSTEM" << endl;
    cout << string(40, '=') << endl;
    cout << "        *****Main Menu*****" << endl;
    cout << endl;
    cout << "1 - Account Menu" << endl;
    cout << "2 - Search Menu" << endl;
    cout << "3 - Service Menu" << endl;
    cout << "4 - Review Menu" << endl;
    cout << "5 - Payment Menu" << endl;
    cout << "6 - Activities Menu" << endl;
    cout << "0 - Exit Option" << endl;
    cout << string(40, '=') << endl;
}