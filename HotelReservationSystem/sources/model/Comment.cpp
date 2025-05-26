// Comment.cpp - tiago

#include "Comment.h"

int Comment::ID = 1;

Comment::Comment(const string& author, const string& text, int rating, const Date& date) {
    this->commentID = ID++;
    this->author = author;
    this->text = text;
    this->rating = rating;
    this->date = date;
}

Comment::Comment(const Comment& obj) {
    this->commentID = obj.commentID;
    this->author = obj.author;
    this->text = obj.text;
    this->rating = obj.rating;
    this->date = obj.date;
}

Comment::~Comment() {}

const string& Comment::getAuthor() const {
    return author;
}

void Comment::setAuthor(const string& author) {
    this->author = author;
}

const string& Comment::getText() const {
    return text;
}

void Comment::setText(const string& text) {
    this->text = text;
}

int Comment::getRating() const {
    return rating;
}

void Comment::setRating(int rating) {
    this->rating = rating;
}

const Date& Comment::getDate() const {
    return date;
}

void Comment::setDate(const Date& date) {
    this->date = date;
}

int Comment::getCommentID() const {
    return commentID;
}

void Comment::setCommentID(int id) {
    this->commentID = id;
}

bool Comment::operator==(const Comment& obj) const {
    return this->commentID == obj.commentID;
}

bool Comment::operator==(int id) const {
    return this->commentID == id;
}
