#include <iostream>
#include "Menu.h"
#include "Users.h"
#include <windows.h>
#include "Markup.h"
#include "Moneys.h"

using namespace std;

int main() {
    Menu menu;
    Users users;
    char choice;

    while(1) {

        if(users.takeIdLoggedUser() == 0) {

            choice = menu.selectOptionFromFirstMenu();

            switch(choice) {

            case '1': {

                users.singIn();
                break;
            }

            case '2': {

                users.registration();
                break;
            }
            case '9': {

                exit(0);
            }
            }
        } else if (users.takeIdLoggedUser() > 0) {

            Moneys moneys(users.takeIdLoggedUser());

            choice = menu.selectOptionFromSecondMenu();

            switch(choice) {

            case '1': {

                moneys.addIncome();
                break;
            }

            case '2': {

                moneys.addExpense();
                break;
            }

            case '3': {

                moneys.balanceOfCurrentMonth();
                break;
            }

            case '4': {

                moneys.balanceOfPastMonth();
                break;
            }

            case '5': {

                moneys.balanceOfDateRange();
                break;
            }

            case '6': {

                users.changePassword();
                break;
            }

            case '7': {

                users.logOut();
                break;
            }

            }
        }
    }

    return 0;
}
