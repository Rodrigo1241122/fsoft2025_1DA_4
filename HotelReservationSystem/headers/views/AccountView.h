// AccountView.h
#ifndef ACCOUNT_VIEW_H
#define ACCOUNT_VIEW_H

class Controller;

class AccountView {
public:
    int menuAccount() const;
    void createAccount(Controller& controller) const;
    void login(Controller& controller) const;
    int menu_logout() const;
    void logout_confirmation();
};

#endif // ACCOUNT_VIEW_H
