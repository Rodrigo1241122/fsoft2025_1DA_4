// AccountView.h
#ifndef ACCOUNT_VIEW_H
#define ACCOUNT_VIEW_H

class Controller;

class AccountView {
public:
    int menuAccount() const;
    void createAccount() const;
    void login(Controller& controller) const;
};

#endif // ACCOUNT_VIEW_H
