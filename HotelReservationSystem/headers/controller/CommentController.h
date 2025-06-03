// CommentController.h - Tiago

#ifndef CONTROLLER_COMMENTCONTROLLER_H
#define CONTROLLER_COMMENTCONTROLLER_H

#include "model/Hotel.h"
#include "model/Comment.h"
#include <string>

class CommentController {
public:
    CommentController();

    void addCommentToHotel(Hotel& hotel, const Comment& comentario);
    std::vector<Comment> viewHotelComments(const Hotel& hotel) const;
};

#endif // CONTROLLER_COMMENTCONTROLLER_H

