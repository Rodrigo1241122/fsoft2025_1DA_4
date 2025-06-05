#include "ReviewView.h"
#include <iostream>
#include <string>

using namespace std;

int ReviewView::menuReview() const {
    int option;
    cout << "\n========================================\n";
    cout << "             Review Menu\n\n";
    cout << "1 - Leave Star Rating\n";
    cout << "2 - Write Comment\n";
    cout << "3 - Submit Review\n\n";
    cout << "0 - Back to Main Menu\n";
    cout << "========================================\n";
    cout << "Option: ";
    cin >> option;
    return option;
}

void ReviewView::leaveStarRating() const {
    int rating;
    cout << "\n++++++++++++++++++++++++++++++++++++++++\n";
    cout << "             Star Rating\n";
    cout << "How do you rate your experience (1-5): ";
    cin >> rating;
}

void ReviewView::writeComment() const {
    string comment;
    cout << "\n++++++++++++++++++++++++++++++++++++++++\n";
    cout << "             Write A Comment\n";
    cout << "Comment: ";
    cin.ignore();  // limpar buffer antes de getline
    getline(cin, comment);
}

void ReviewView::submitReview() const {
    cout << "\n++++++++++++++++++++++++++++++++++++++++\n";
    cout << "           Review Submitted\n";
    cout << "Thanks for rating your experience and writing a comment!" << endl;
}
