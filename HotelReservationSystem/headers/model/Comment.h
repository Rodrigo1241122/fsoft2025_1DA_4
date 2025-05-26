// Comment.h - tiago

#ifndef HEADERS_MODEL_COMMENT_H_
#define HEADERS_MODEL_COMMENT_H_

#include <string>
#include "Date.h"

using namespace std;

class Comment {
private:
    static int ID;
    int commentID;
    string author;
    string text;
    int rating; // 1 a 5 estrelas
    Date date;

public:
    Comment(const string& author, const string& text, int rating, const Date& date);
    Comment(const Comment& obj);
    ~Comment();

    const string& getAuthor() const;
    void setAuthor(const string& author);

    const string& getText() const;
    void setText(const string& text);

    int getRating() const;
    void setRating(int rating);

    const Date& getDate() const;
    void setDate(const Date& date);

    int getCommentID() const;
    void setCommentID(int id);

    bool operator == (const Comment& obj) const;
    bool operator == (int id) const;
};

#endif /* HEADERS_MODEL_COMMENT_H_ */
