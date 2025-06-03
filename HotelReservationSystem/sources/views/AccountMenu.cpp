#include "AccountMenu.h"
#include <iostream>
#include <string>

using namespace std;

void AccountMenu::display_account_menu() {
    cout << "\n" << string(40, '=') << endl;
    cout << "        ****Account Menu****" << endl;
    cout << endl;
    cout << "1 - Create Account" << endl;
    cout << "2 - Log In" << endl;
    cout << endl;
    cout << "0 - Back to Main Menu" << endl;
    cout << string(40, '=') << endl;
}