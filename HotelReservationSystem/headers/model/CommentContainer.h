// CommentContainer.h - Tiago

#ifndef HEADERS_MODEL_COMMENTCONTAINER_H_
#define HEADERS_MODEL_COMMENTCONTAINER_H_

#include <vector>
#include "model/Comment.h"

class CommentContainer {
private:
    std::vector<Comment> comments;

public:
    void addComment(const Comment& comment);
    std::vector<Comment>& getAllComments();
    const std::vector<Comment>& getAllComments() const;
};

#endif /* HEADERS_MODEL_COMMENTCONTAINER_H_ */
