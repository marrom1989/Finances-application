#include "ExpensesFile.h"

ExpensesFile::ExpensesFile() {

    this->nameOfSaveExpenses = "Expenses.xml";
}

ExpensesFile::~ExpensesFile() {;}

void ExpensesFile::saveFirstExpense(Expenses expense) {

    CMarkup document;

    document.AddElem( "EXPENSES" );
    document.IntoElem();
    document.AddElem("DATA");
    document.IntoElem();
    document.AddElem("EXPENSESID", expense.getExpenseId());
    document.AddElem( "USERID", expense.getUserId());
    document.AddElem( "DATE", expense.getDate());
    document.AddElem( "ITEM", expense.getItem());
    document.AddElem( "AMOUNT", expense.getAmount());

    document.Save(nameOfSaveExpenses.c_str());
}

void ExpensesFile::saveNextExpense(Expenses expense) {

    CMarkup document;

    document.Load(nameOfSaveExpenses);
    document.FindElem();
    document.IntoElem();

    document.AddElem("DATA");
    document.IntoElem();
    document.AddElem("EXPENSESID", expense.getExpenseId());
    document.AddElem( "USERID", expense.getUserId());
    document.AddElem( "DATE", expense.getDate());
    document.AddElem( "ITEM", expense.getItem());
    document.AddElem( "AMOUNT", expense.getAmount());

    document.Save(nameOfSaveExpenses.c_str());

}

void ExpensesFile::loadExpensesToVector(vector<Expenses> &expenses, int loggedInUserId) {

    Expenses expense;
    CMarkup document;
    int expenseId;
    int userId;
    int date;
    string item;
    string amount;


    document.Load(nameOfSaveExpenses);
    document.FindElem();
    document.IntoElem();

    while(document.FindElem("DATA")) {

        document.IntoElem();
        document.FindElem("USERID");
        expenseId = atoi(MCD_2PCSZ(document.GetData()));
        if(expenseId == loggedInUserId) {

            document.ResetMainPos();
            document.IntoElem();
            document.FindElem("EXPENSESID");
            expenseId = atoi(MCD_2PCSZ(document.GetData()));
            expense.setExpenseId(expenseId);

            document.FindElem("USERID");
            userId = atoi(MCD_2PCSZ(document.GetData()));
            expense.setUserId(userId);

            document.FindElem("DATE");
            date = atoi(MCD_2PCSZ(document.GetData()));
            expense.setDate(date);

            document.FindElem("ITEM");
            item = document.GetData();
            expense.setItem(item);

            document.FindElem("AMOUNT");
            amount = document.GetData();
            expense.setAmount(amount);
            document.OutOfElem();
            expenses.push_back(expense);

        } else {
        document.OutOfElem();
    }
    }

}




