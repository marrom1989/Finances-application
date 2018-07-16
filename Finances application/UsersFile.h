#include <iostream>
#include "Markup.h"
#include "User.h"
#include "Users.h"

#ifndef USERSFILE_H
#define USERSFILE_H

class UsersFile {

string nameXmlFileOfUsers;

public:
    UsersFile();
    ~UsersFile();
    void saveUserInXmlFile(User user, vector<User> &users);
    void loadUsersFromXmlFile(vector<User> &users);
    void saveAllUsersIntoFile(vector<User> &users);


};




#endif
