#include "Users.h"

Users::Users() {

    this->idLoggedUser = 0;
    usersFile.loadUsersFromXmlFile(users);
}

Users::~Users() {

    users.clear();
}

void Users::registration() {

    User user = enterTheDetailsOfTheNewUser();
    users.push_back(user);
    usersFile.saveUserInXmlFile(user, users);
}

bool Users:: doesUserExist (string login) {
    vector<User>::iterator itr = users.begin();

    while (itr != users.end()) {
        if(itr->User::getLogin() == login) {

            cout << "That user exist !!" << endl;
            Sleep(2000);
            return true;
        } else {

            itr++;
        }
    }
    return false;
}


User Users::enterTheDetailsOfTheNewUser() {

    User user;
    string name = "";
    string surname = "";
    string login = "";
    string password = "";

    user.setUserId(takeIdNewUser());

    cout << endl << "Enter name: ";
    cin >> name;
    user.setName(name);

    cout << endl << "Enter surname: ";
    cin >> surname;
    user.setSurname(surname);

    do {

        cout << endl << "Enter login: ";
        cin >> login;
        cin.ignore();
        user.setLogin(login);

    } while (doesUserExist(login) == true);

    do {
        cout << endl << "Enter password: ";
        cin >> password;

        if (password.length() < 3) {

            cout << "Password is to short!! Enter different password." << endl;
            Sleep(2000);
        }
        user.setPassword(password);
    } while (password.length() < 3);

    return user;
}

void Users::singIn() {

    string login, password;
    int attempt = 3;
    bool doesUserExist = false;

    cout << "Please, enter your username: ";
    cin >> login;

    for(vector<User>::iterator itr = users.begin(), koniec = users.end(); itr != koniec; ++itr) {
        if(itr->User::getLogin() == login) {

            while(attempt > 0) {
                cout << "Left attempts: " << attempt << " Enter password: ";
                cin >> password;

                if(itr->User::getPassword() == password) {

                    cout << "You logged in !!" << endl;
                    Sleep(1000);
                    this->idLoggedUser = itr->User::getUserId();
                    doesUserExist = true;
                    break;
                }
                attempt--;

                if(attempt == 0) {
                    cout << "Three times you wrote wrong password. Wait 3 seconds and try again !!" << endl;
                    Sleep(3000);
                    this->idLoggedUser = 0;
                    break;
                }
            }
        }
    }
    if(doesUserExist == false) {
        cout << "There is no user with that login !!" << endl;
        Sleep(1500);
    }
}



void Users::changePassword() {

    if(idLoggedUser > 0) {

        string password = "";
        cout << "Enter new password: ";
        cin >> password;

       for(vector<User>::iterator itr = users.begin(), koniec = users.end(); itr != koniec; ++itr) {

            if(itr->User::getUserId() == idLoggedUser) {

                itr->User::setPassword(password);
                cout << "Password has been changed !!" << endl;
                Sleep(1500);
            }
            usersFile.saveAllUsersIntoFile(users);
        }
    }
}



int Users::takeIdNewUser() {

    if(users.size() == 0) {

        return 1;
    } else {

        return users.back().getUserId() + 1;
    }

}

int Users::takeIdLoggedUser() {

    return idLoggedUser;
}


void Users::logOut() {

this->idLoggedUser = 0;
}

