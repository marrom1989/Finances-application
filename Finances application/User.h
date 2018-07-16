#include <iostream>

using namespace std;

#ifndef USER_H
#define USER_H


class User {

int userId;
string name;
string surname;
string login;
string password;
friend class UsersFile;

public:
    User();
    virtual ~User();

    int getUserId();
    string getName();
    string getSurname();
    string getLogin();
    string getPassword();

    void setUserId(int userId);
    void setName(string name);
    void setSurname(string surname);
    void setLogin(string login);
    void setPassword(string password);

};

#endif
