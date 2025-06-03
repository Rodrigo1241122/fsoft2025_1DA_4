#include "ReviewMenu.h"
#include <iostream>
#include <string>

using namespace std;

void ReviewMenu::display_review_menu() {
    cout << "\n" << string(40, '=') << endl;
    cout << "        ****Review Menu****" << endl;
    cout << endl;
    cout << "1 - Leave Star Rating" << endl;
    cout << "2 - Write Comment" << endl;
    cout << "3 - Submit Review" << endl;
    cout << endl;
    cout << "0 - Back to Main Menu" << endl;
    cout << string(40, '=') << endl;
}