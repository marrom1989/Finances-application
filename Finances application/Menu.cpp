#include <iostream>
#include "Menu.h"
#include <windows.h>

using namespace std;

char Menu::selectOptionFromFirstMenu() {

    char choice;

    system("cls");
    cout << endl << ">>> BUDGET MENU <<<" << endl;
    cout << "--------------------" << endl;
    cout << "1. Sing In" << endl;
    cout << "2. Registration" << endl;
    cout << "9. Exit" << endl;
    cout << "--------------------" << endl;
    cout << "Your choice: ";

    cin >> choice;
    return choice;
}

char Menu::selectOptionFromSecondMenu() {


    char choice;

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Balance from the current month" << endl;
    cout << "4. Balance from the past month" << endl;
    cout << "5. Balance from selected range" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Change password" << endl;
    cout << "7. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    cin >> choice;
    cin.ignore();

    return choice;

}

