#ifndef USERS_H
#define USERS_H

#include <iostream>
#include <vector>
#include "User.h"
#include <windows.h>
#include "UsersFile.h"


class Users{

int idLoggedUser;
vector<User> users;
UsersFile usersFile;

public:
    Users();
    virtual ~Users();
    int takeIdLoggedUser();
    void registration();
    void singIn();
    void changePassword();
    void logOut();


private:
    User enterTheDetailsOfTheNewUser();
    int takeIdNewUser();
    bool doesUserExist(string login);

};


#endif
