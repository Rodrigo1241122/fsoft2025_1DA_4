#include "ServiceMenu.h"
#include <iostream>
#include <string>

using namespace std;

void ServiceMenu::display_service_menu() {
    cout << "\n" << string(40, '=') << endl;
    cout << "        ****Service Menu****" << endl;
    cout << endl;
    cout << "1 - View Available Services" << endl;
    cout << "2 - Request a Service" << endl;
    cout << endl;
    cout << "0 - Back to Main Menu" << endl;
    cout << string(40, '=') << endl;
}