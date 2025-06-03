#include "InformationMenu.h"
#include <iostream>
#include <string>

using namespace std;

void InformationMenu::display_information_menu() {
    cout << "\n" << string(40, '=') << endl;
    cout << "        ****Informations Menu****" << endl;
    cout << endl;
    cout << "1 - View Hotel Information" << endl;
    cout << "2 - View Room Information" << endl;
    cout << endl;
    cout << "0 - Back to Search Menu" << endl;
    cout << string(40, '=') << endl;
}