#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

using namespace std;


class Expenses {

int expenseId;
int userId;
int date;
string item;
string amount;

public:
    Expenses();
    virtual ~Expenses();
    int getExpenseId();
    int getUserId();
    int getDate();
    string getItem();
    string getAmount();
    bool operator <(const Expenses& s2) const;

    void setExpenseId(int expenseId);
    void setUserId(int userId);
    void setDate(int date);
    void setItem(string item);
    void setAmount(string amount);

};


#endif // EXPENSE_H
