#include "ReviewView.h"
#include <iostream>
#include <string>
#include "model/Comment.h"
#include "model/CommentContainer.h"
#include "date.h"
#include "client.h"


using namespace std;

int ReviewView::menuReview() const {
    int option;
    cout << "\n========================================\n";
    cout << "             Review Menu\n\n";
    cout << "1 - Leave Star Rating\n";
    cout << "2 - Write Comment\n";
    cout << "3 - Submit Review\n";
    cout << "4 - View Reviews\n\n";
    cout << "0 - Back to Main Menu\n";
    cout << "========================================\n";
    cout << "Option: ";
    cin >> option;
    return option;
}

void ReviewView::leaveStarRating(int& rating) const {
    cout << "\n++++++++++++++++++++++++++++++++++++++++\n";
    cout << "             Star Rating\n";
    cout << "How do you rate your experience (1-5): ";
    cin >> rating;
}

void ReviewView::writeComment(string& comment) const {
    cout << "\n++++++++++++++++++++++++++++++++++++++++\n";
    cout << "             Write A Comment\n";
    cout << "Comment: ";
    cin.ignore();
    getline(cin, comment);
}

void ReviewView::submitReview(int rating, const string& comment, CommentContainer& container) const {
    Date today = getTodayDate();

    int day,month,year;
    today.getDate(day,month,year);

    cout << "\n++++++++++++++++++++++++++++++++++++++++\n";
    cout << "           Review Submitted\n";
    cout << "Stars Rating: " << rating << endl;
    cout << "Your review: " << comment << endl;
    cout << "Date: " << day << "/" << month << "/" << year << endl;
    cout << "Thanks for rating your experience and writing a comment!" << endl;
}

void ReviewView::view_review(const CommentContainer& container) const {
    cout << "\n++++++++++++++++++++++++++++++++++++++++\n";
    cout << "         Reviews\n";
    const auto& comments = container.getAllComments();
    if (comments.empty()) {
        cout << "No reviews yet.\n";
    }
    else {
        for (const auto& comment : comments) {
            Date d = comment.getDate();
            int day,month,year;
            d.getDate(day,month,year);

            cout << "------------------------------\n";
            cout << "ID: " << comment.getCommentID() << endl;
            cout << "Author: " << comment.getAuthor() << endl;
            cout << "Rating: " << comment.getRating() << endl;
            cout << "Comment: " << comment.getText() << endl;
            cout << "Date: " << day << "/" << month << "/" << year << endl;
        }
    }
    cout << "++++++++++++++++++++++++++++++++++++++++\n";
}

void ReviewView::login_review() const {
    cout << "------------------------------\n";
    cout << "You must be logged in to submit a review.\n\n";
    cout << "++++++++++++++++++++++++++++++++++++++++\n";
}

void ReviewView::incorrect_rating() const {
    cout << "------------------------------\n";
    cout << "Rating must be a number between 1 and 5.\n\n";
}
