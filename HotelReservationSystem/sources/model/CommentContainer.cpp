// CommentContainer.cpp - Tiago

#include "model/CommentContainer.h"

void CommentContainer::addComment(const Comment& comment) {
    comments.push_back(comment);
}

std::vector<Comment>& CommentContainer::getAllComments() {
    return comments;
}

const std::vector<Comment>& CommentContainer::getAllComments() const {
    return comments;
}
