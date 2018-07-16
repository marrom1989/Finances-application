#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H

#include <iostream>
#include "Expenses.h"
#include <vector>
#include "Markup.h"


using namespace std;

class ExpensesFile {

string nameOfSaveExpenses;

public:
    ExpensesFile();
    virtual ~ExpensesFile();
    void saveFirstExpense(Expenses expense);
    void saveNextExpense(Expenses expense);
    void loadExpensesToVector(vector<Expenses> &expenses, int loggedInUserId);


};




#endif // EXPENSESFILE_H
