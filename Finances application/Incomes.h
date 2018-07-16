#ifndef INCOMES_H
#define INCOMES_H

#include <iostream>

using namespace std;

class Incomes{

int incomeId;
int userId;
int date;
string item;
string amount;
friend class IncomesFile;


public:
    Incomes();
    virtual ~Incomes();
    int getIncomeId();
    int getUserId();
    int getDate();
    string getItem();
    string getAmount();
    bool operator <(const Incomes& s2) const;

    void setIncomeId(int incomeId);
    void setUserId(int userId);
    void setDate(int date);
    void setItem(string item);
    void setAmount(string amount);
};


#endif // INCOMES_H
