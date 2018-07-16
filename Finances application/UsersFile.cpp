#include "UsersFile.h"

UsersFile::UsersFile() {

    nameXmlFileOfUsers = "Users.xml";
}

UsersFile::~UsersFile() {;}

void UsersFile::saveUserInXmlFile(User user, vector<User> &users) {

    CMarkup document;

    if(users.size() <= 1) {
        document.AddElem( "USERS" );
        document.IntoElem();
        document.AddElem("DATA");
        document.IntoElem();
        document.AddElem( "ID", user.getUserId());
        document.AddElem( "NAME", user.getName());
        document.AddElem( "SURNAME", user.getSurname());
        document.AddElem( "LOGIN", user.getLogin());
        document.AddElem( "PASSWORD", user.getPassword());

        document.Save(nameXmlFileOfUsers.c_str());

    } else {

        document.Load(nameXmlFileOfUsers);
        document.FindElem();
        document.IntoElem();

        document.AddElem("DATA");
        document.IntoElem();
        document.AddElem( "ID", user.getUserId());
        document.AddElem( "NAME", user.getName());
        document.AddElem( "SURNAME", user.getSurname());
        document.AddElem( "LOGIN", user.getLogin());
        document.AddElem( "PASSWORD", user.getPassword());

        document.Save(nameXmlFileOfUsers.c_str());

    }
}

void UsersFile::loadUsersFromXmlFile(vector<User> &users) {

    User user;
    CMarkup document;
    int id;
    string name;
    string surname;
    string login;
    string password;


    document.Load(nameXmlFileOfUsers);
    document.FindElem();
    document.IntoElem();

    while(document.FindElem("DATA")) {

        document.IntoElem();
        document.FindElem("ID");
        id = atoi(MCD_2PCSZ(document.GetData()));
        user.setUserId(id);

        document.FindElem("NAME");
        name = document.GetData();
        user.setName(name);

        document.FindElem("SURNAME");
        surname = document.GetData();
        user.setSurname(surname);

        document.FindElem("LOGIN");
        login = document.GetData();
        user.setLogin(login);

        document.FindElem("PASSWORD");
        password = document.GetData();
        user.setPassword(password);
        document.OutOfElem();
        users.push_back(user);
    }
}

void UsersFile::saveAllUsersIntoFile(vector<User> &users) {

    CMarkup document;


    document.AddElem( "USERS" );
    document.IntoElem();
    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        document.AddElem("DATA");
        document.IntoElem();
        document.AddElem( "ID", itr-> userId);
        document.AddElem( "NAME", itr-> name);
        document.AddElem( "SURNAME", itr->surname);
        document.AddElem( "LOGIN", itr->login);
        document.AddElem( "PASSWORD", itr->password);
        document.OutOfElem();

    }

    document.Save(nameXmlFileOfUsers.c_str());

}
