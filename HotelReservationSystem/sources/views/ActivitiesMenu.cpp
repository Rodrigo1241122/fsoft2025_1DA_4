#include "ActivitiesMenu.h"
#include <iostream>
#include <string>

using namespace std;

void ActivitiesMenu::display_activities_menu() {
    cout << "\n" << string(40, '=') << endl;
    cout << "        ****Activities Menu****" << endl;
    cout << endl;
    cout << "1 - View Hotel Activities" << endl;
    cout << "2 - Register for an Activity" << endl;
    cout << endl;
    cout << "0 - Back to Main Menu" << endl;
    cout << string(40, '=') << endl;
}