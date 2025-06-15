#ifndef REVIEWVIEW_H
#define REVIEWVIEW_H

#include "model/CommentContainer.h"
#include "model/Date.h"

class ReviewView {
public:
    int menuReview() const;
    void leaveStarRating(int& rating) const;
    void writeComment(std::string& comment) const;
    void submitReview(int rating, const std::string& coment, CommentContainer& container) const;
    void view_review(const CommentContainer& container) const;
    void login_review() const;
    void incorrect_rating() const;
};

#endif
