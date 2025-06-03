// CommentController.cpp - Tiago

#include "controller/CommentController.h"

CommentController::CommentController() {}

void CommentController::addCommentToHotel(Hotel& hotel, const Comment& comentario) {
    hotel.getCommentContainer().addComment(comentario);
}

std::vector<Comment> CommentController::viewHotelComments(const Hotel& hotel) const {
    return hotel.getCommentContainer().getAllComments();
}
