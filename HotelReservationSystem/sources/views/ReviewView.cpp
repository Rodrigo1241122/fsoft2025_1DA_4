//reviewview.cpp
#include "ReviewView.h"
#include <iostream>
#include <string>

using namespace std;

void ReviewView::display_review_menu() {
    int option;

    cout << "\n" << string(40, '=') << endl;
    cout << "        Review Menu" << endl;
    cout << endl;
    cout << "1 - Leave Star Rating" << endl;
    cout << "2 - Write Comment" << endl;
    cout << "3 - Submit Review" << endl;
    cout << endl;
    cout << "0 - Back to Main Menu" << endl;
    cout << string(40, '=') << endl;
    cin >> option;
}

void ReviewView::star_rating() {
    int rating;
    cout << "\n" << string(40,'+') << endl;
    cout << "        Star Rating" << endl;
    cout << "How do you rate your experience (1-5): ";
    cin >> rating; 
}

void ReviewView::write_comment() {
    string comment;
    cout << "\n" << string(40,'+') << endl;
    cout << "        Write A Comment" << endl;
    cin >> comment;
}

void ReviewView::submit_review() {
    int submit;
    cout << "\n" << string(40,'+') << endl;
    cout << "        Review Submited" << endl;
    cout << "Thanks for rating your experience and writing a comment!" << endl;
    cout << "Press 0 to return to the main menu." << endl;
    cin >> submit;
}
