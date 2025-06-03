#include "SearchMenu.h"
#include <iostream>
#include <string>

using namespace std;

void SearchMenu::display_search_menu() {
    cout << "\n" << string(40, '=') << endl;
    cout << "        ****Search Menu****" << endl;
    cout << endl;
    cout << "1 - Search Available Rooms" << endl;
    cout << "2 - Choose Room" << endl;
    cout << "3 - Informations" << endl;
    cout << "4 - Reserve a Room" << endl;
    cout << "5 - Apply Discount Coupon" << endl;
    cout << "6 - Cancel Reservation" << endl;
    cout << endl;
    cout << "0 - Back to Main Menu" << endl;
    cout << string(40, '=') << endl;
}