#include "IncomesFile.h"

IncomesFile::IncomesFile() {

    this->nameOfSaveIncomes = "Incomes.xml";
}

IncomesFile::~IncomesFile() {;}

void IncomesFile::saveFirstIncome(Incomes income) {

    CMarkup document;

    document.AddElem( "INCOMES" );
    document.IntoElem();
    document.AddElem("DATA");
    document.IntoElem();
    document.AddElem("INCOMEID", income.getIncomeId());
    document.AddElem( "USERID", income.getUserId());
    document.AddElem( "DATE", income.getDate());
    document.AddElem( "ITEM", income.getItem());
    document.AddElem( "AMOUNT", income.getAmount());

    document.Save(nameOfSaveIncomes.c_str());
}

void IncomesFile::saveNextIncomes(Incomes income) {

    CMarkup document;

    document.Load(nameOfSaveIncomes);
    document.FindElem();
    document.IntoElem();

    document.AddElem("DATA");
    document.IntoElem();
    document.AddElem("INCOMEID", income.getIncomeId());
    document.AddElem( "USERID", income.getUserId());
    document.AddElem( "DATE", income.getDate());
    document.AddElem( "ITEM", income.getItem());
    document.AddElem( "AMOUNT", income.getAmount());

    document.Save(nameOfSaveIncomes.c_str());

}

void IncomesFile::loadIncomesToVector(vector<Incomes> &incomes, int loggedInUserId) {

    Incomes income;
    CMarkup document;
    int incomeId;
    int userId;
    int date;
    string item;
    string amount;


    document.Load(nameOfSaveIncomes);
    document.FindElem();
    document.IntoElem();

    while(document.FindElem("DATA")) {

        document.IntoElem();
        document.FindElem("USERID");
        incomeId = atoi(MCD_2PCSZ(document.GetData()));
        if(incomeId == loggedInUserId) {

            document.ResetMainPos();
            document.IntoElem();
            document.FindElem("INCOMEID");
            incomeId = atoi(MCD_2PCSZ(document.GetData()));
            income.setIncomeId(incomeId);

            document.FindElem("USERID");
            userId = atoi(MCD_2PCSZ(document.GetData()));
            income.setUserId(userId);

            document.FindElem("DATE");
            date = atoi(MCD_2PCSZ(document.GetData()));
            income.setDate(date);

            document.FindElem("ITEM");
            item = document.GetData();
            income.setItem(item);

            document.FindElem("AMOUNT");
            amount = document.GetData();
            income.setAmount(amount);
            document.OutOfElem();
            incomes.push_back(income);

        } else {
        document.OutOfElem();
    }
    }

}




