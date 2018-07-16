#ifndef MONEYS_H
#define MONEYS_H

#include <iostream>
#include <vector>
#include "Incomes.h"
#include "Expenses.h"
#include "Users.h"
#include <algorithm>
#include <sstream>
#include "IncomesFile.h"
#include "ExpensesFile.h"
#include <conio.h>
#include "Convert.h"

using namespace std;

class Moneys{

IncomesFile incomesFile;
ExpensesFile expensesFile;
Convert convert;
vector<Incomes> incomes;
vector<Expenses> expenses;
Users users;
int loggedInUserId;
string date;
string tempDate;
string amount;

public:
    Moneys(int loggedInUserId);
    virtual ~Moneys();
    int getIdLoggedUser();
    void addIncome();
    void addExpense();
    void balanceOfCurrentMonth();
    void balanceOfPastMonth();
    void balanceOfDateRange();

private:
    Incomes enterIncomesDetails();
    Expenses enterExpensesDetails();
    bool checkIfDateIsCorect(string year, string month, string day);
    int numberOfDaysInMonth(int month, int year);
    bool isLeapYear(int year);
    int takeIdOfNewIncome();
    int takeIdOfNewExpense();
    int startOfMonth(int year, int month);
    int endOfMonth(int year, int month);
    void incomesBalance(int startDayOfMonth, int endDayOfMonth);
    void expensesBalance(int startDayOfMonth, int endDayOfMonth);
    double sumOfIncome(int startDayOfMonth,int endDayOfMonth);
    double sumOfExpense(int startDayOfMonth,int endDayOfMonth);

};

#endif // MONEYS_H
