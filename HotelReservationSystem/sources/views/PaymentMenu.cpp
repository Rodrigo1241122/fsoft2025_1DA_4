#include "PaymentMenu.h"
#include <iostream>
#include <string>

using namespace std;

void PaymentMenu::display_payment_menu() {
    cout << "\n" << string(40, '=') << endl;
    cout << "        ****Payment Menu****" << endl;
    cout << endl;
    cout << "1 - Pay for a Reservation" << endl;
    cout << "2 - View Payment Details" << endl;
    cout << endl;
    cout << "0 - Back to Main Menu" << endl;
    cout << string(40, '=') << endl;
}