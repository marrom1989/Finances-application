#include "Moneys.h"

Moneys::Moneys(int loggedInUserId) {

    this->loggedInUserId = loggedInUserId;
    date = "";
    tempDate = "";
    amount = "";
    incomesFile.loadIncomesToVector(incomes, loggedInUserId);
    expensesFile.loadExpensesToVector(expenses, loggedInUserId);
}


Moneys::~Moneys() {

    incomes.clear();
    expenses.clear();
}

int Moneys::getIdLoggedUser() {

    return loggedInUserId;
}

void Moneys::addIncome() {

    CMarkup document;
    document.Load("Incomes.xml");

    Incomes income = enterIncomesDetails();
    incomes.push_back(income);

    if(document.FindElem("INCOMES") != true) {

        incomesFile.saveFirstIncome(income);
    } else {

        incomesFile.saveNextIncomes(income);
    }
}

Incomes Moneys::enterIncomesDetails() {

    Incomes income;
    SYSTEMTIME st;
    GetLocalTime(&st);

    int month = st.wMonth;
    int year = st.wYear;
    int day = st.wDay;
    char choice;
    string item = "";
    string amount = "";

    cout << endl << "Income relates to today or another date? Enter press <t> if today or press <d> id different date: ";
    cin >> choice;

    switch(choice) {

    case 't': {

        income.setIncomeId(takeIdOfNewIncome());
        income.setUserId(getIdLoggedUser());
        income.setDate(convert.convertStringToInt(convert.convertYearToString(year) + convert.convertMonthToString(month) + convert.convertDayToString(day)));

        cout << endl << "Enter item: " ;
        cin.ignore();
        getline(cin, item);
        income.setItem(item);

        cout << endl << "Enter amount: ";
        cin >> amount;
        income.setAmount(convert.convertCommaToDot(amount));

        return income;


    }
    case 'd': {

        income.setIncomeId(takeIdOfNewIncome());
        income.setUserId(getIdLoggedUser());

        do {

            cout << endl << "Enter date. <rrrr-mm-dd> ";
            cin.sync();
            getline(cin, date);

        } while(checkIfDateIsCorect(convert.spreadYear(date), convert.spreadMonth(date), convert.spreadDay(date)) == false);
        income.setDate(convert.convertStringToInt(convert.spreadYear(date) + convert.spreadMonth(date) + convert.spreadDay(date)));

        cout << endl << "Enter item: " ;
        getline(cin, item);
        income.setItem(item);

        cout << endl << "Enter amount: ";
        cin >> amount;
        income.setAmount(convert.convertCommaToDot(amount));

        return income;
    }
    }
}

void Moneys::addExpense() {

    CMarkup document;
    document.Load("Expenses.xml");

    Expenses expense = enterExpensesDetails();
    expenses.push_back(expense);

    if(document.FindElem("EXPENSES") != true) {

        expensesFile.saveFirstExpense(expense);
    } else {

        expensesFile.saveNextExpense(expense);
    }
}

Expenses Moneys::enterExpensesDetails() {

    Expenses expense;
    SYSTEMTIME st;
    GetLocalTime(&st);

    int month = st.wMonth;
    int year = st.wYear;
    int day = st.wDay;

    char choice;
    string item = "";
    string amount = "";

    cout << endl << "Expense relates to today or another date? Enter press <t> if today or <d> if different date: ";
    cin >> choice;

    switch(choice) {

    case 't': {


        expense.setExpenseId(takeIdOfNewExpense());
        expense.setUserId(getIdLoggedUser());
        expense.setDate(convert.convertStringToInt(convert.convertYearToString(year) + convert.convertMonthToString(month) + convert.convertDayToString(day)));

        cout << endl << "Enter item: " ;
        cin.ignore();
        getline(cin, item);
        expense.setItem(item);

        cout << endl << "Enter amount: ";
        cin >> amount;
        expense.setAmount(convert.convertCommaToDot(amount));

        return expense;


    }
    case 'd': {

        expense.setExpenseId(takeIdOfNewExpense());
        expense.setUserId(getIdLoggedUser());

        do {

            cout << endl << "Enter date. <rrrr-mm-dd> ";
            cin.sync();
            getline(cin, date);

        } while(checkIfDateIsCorect(convert.spreadYear(date), convert.spreadMonth(date), convert.spreadDay(date)) == false);
        expense.setDate(convert.convertStringToInt(convert.spreadYear(date) + convert.spreadMonth(date) + convert.spreadDay(date)));

        cout << endl << "Enter item: " ;
        getline(cin, item);
        expense.setItem(item);

        cout << endl << "Enter amount: ";
        cin >> amount;
        expense.setAmount(convert.convertCommaToDot(amount));

        return expense;
    }
    }

}

void Moneys::balanceOfCurrentMonth() {

    SYSTEMTIME st;
    GetLocalTime(&st);

    int year = st.wYear;
    int month = st.wMonth;

    double income = 0.0;
    double expense = 0.0;

    sort(incomes.begin(), incomes.end());
    sort(expenses.begin(), expenses.end());

    int startDayOfMonth = startOfMonth(year, month);
    int endDayOfMonth = endOfMonth(year, month);

    system("cls");
    cout << endl << "Balance of current month: " << convert.nameOfMonth(month) << endl;

    cout << endl << "<<<INCOMES>>>" << endl;

    incomesBalance(startDayOfMonth, endDayOfMonth);

    cout << endl << "<<<EXPENSES>>>" << endl;
    expensesBalance(startDayOfMonth, endDayOfMonth);

    cout << endl << "Your incomes balance from " << convert.nameOfMonth(month) << " is: " << sumOfIncome(startDayOfMonth,endDayOfMonth) << endl;
    getch();
    cout << endl << "Your expenses balance from " << convert.nameOfMonth(month) << " is: " << sumOfExpense(startDayOfMonth,endDayOfMonth) << endl;
    getch();
    cout << endl << "Your total balance from " << convert.nameOfMonth(month) << " is: " << sumOfIncome(startDayOfMonth,endDayOfMonth) - sumOfExpense(startDayOfMonth,endDayOfMonth) << endl;
    getch();

}

void Moneys::balanceOfPastMonth() {

    SYSTEMTIME st;
    GetLocalTime(&st);

    int year = st.wYear;
    int month = st.wMonth;
    double income = 0.0;
    double expense = 0.0;

    sort(incomes.begin(), incomes.end());
    sort(expenses.begin(), expenses.end());

    int startDayOfMonth = startOfMonth(year, month - 1);
    int endDayOfMonth = endOfMonth(year, month - 1);

    system("cls");
    cout << endl << "Balance of current month: " << convert.nameOfMonth(month) << endl;

    cout << endl << "<<<INCOMES>>>" << endl;

    incomesBalance(startDayOfMonth, endDayOfMonth);

    cout << endl << "<<<EXPENSES>>>" << endl;
    expensesBalance(startDayOfMonth, endDayOfMonth);

    cout << endl << "Your incomes balance from " << convert.nameOfMonth(month) << " is: " << sumOfIncome(startDayOfMonth,endDayOfMonth) << endl;
    getch();
    cout << endl << "Your expenses balance from " << convert.nameOfMonth(month) << " is: " << sumOfExpense(startDayOfMonth,endDayOfMonth) << endl;
    getch();
    cout << endl << "Your total balance from " << convert.nameOfMonth(month) << " is: " << sumOfIncome(startDayOfMonth,endDayOfMonth) - sumOfExpense(startDayOfMonth,endDayOfMonth) << endl;
    getch();

}

void Moneys::balanceOfDateRange() {

    string startDate = "";
    string endDate = "";
    int firstDate = 0;
    int secondDate = 0;

    do {

        cout << endl << "Please enter start date of range. <rrrr-mm-dd> : ";
        cin.sync();
        getline(cin, startDate);

    } while(checkIfDateIsCorect(convert.spreadYear(startDate), convert.spreadMonth(startDate), convert.spreadDay(startDate)) == false);
    firstDate = convert.convertStringToInt(convert.spreadYear(startDate) + convert.spreadMonth(startDate) + convert.spreadDay(startDate));

    do {

        cout << endl << "Please enter start date of range. <rrrr-mm-dd> : ";
        cin.sync();
        getline(cin, endDate);

    } while(checkIfDateIsCorect(convert.spreadYear(endDate), convert.spreadMonth(endDate), convert.spreadDay(endDate)) == false);
    secondDate = convert.convertStringToInt(convert.spreadYear(endDate) + convert.spreadMonth(endDate) + convert.spreadDay(endDate));

    sort(incomes.begin(), incomes.end());
    sort(expenses.begin(), expenses.end());

    system("cls");
    cout << endl << "Balance of current month: " << startDate << "  :  " <<  endDate << endl;

    cout << endl << "<<<INCOMES>>>" << endl;

    incomesBalance(firstDate, secondDate);

    cout << endl << "<<<EXPENSES>>>" << endl;
    expensesBalance(firstDate, secondDate);

    cout << endl << "Your incomes balance from " << startDate << "  :  " <<  endDate  << " is: " << sumOfIncome(firstDate,secondDate) << endl;
    getch();
    cout << endl << "Your expenses balance from " << startDate << "  :  " <<  endDate << " is: " << sumOfExpense(firstDate,secondDate) << endl;
    getch();
    cout << endl << "Your total balance from " << startDate << "  :  " <<  endDate << " is: " << sumOfIncome(firstDate,secondDate) - sumOfExpense(firstDate,secondDate) << endl;
    getch();
}

bool Moneys::isLeapYear(int year) {

    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {

        return true;
    } else {

        return false;
    }
}

int Moneys::numberOfDaysInMonth(int month, int year) {

    int numberOfDays;
    if (month == 4 || month == 6 || month == 9 || month == 11) {

        numberOfDays = 30;
        return numberOfDays;
    } else if (month == 2) {

        isLeapYear(year);

        if (isLeapYear(year) == true) {
            numberOfDays = 29;
            return numberOfDays;

        } else {
            numberOfDays = 28;
            return numberOfDays;

        }
    } else {
        numberOfDays = 31;
        return numberOfDays;
    }
}

bool Moneys::checkIfDateIsCorect(string year, string month, string day) {

    SYSTEMTIME st;
    GetLocalTime(&st);

    int moonth = st.wMonth;
    int yeaar = st.wYear;

    int changeStringYearToInt = atoi(year.c_str());
    int changeStringMonthToInt = atoi(month.c_str());
    int changeStringDayToInt = atoi(day.c_str());

    if(changeStringYearToInt >= 2000 && changeStringYearToInt <= yeaar ) {

        if(changeStringMonthToInt >= 1 && changeStringMonthToInt <= 12) {
            if(((changeStringYearToInt == yeaar) && (changeStringMonthToInt > moonth)) || ((changeStringYearToInt < 2000))) {

                cout << endl << "Date is behind range. Enter new date!!" <<endl;
                Sleep(1500);
                return false;

            } else if(changeStringDayToInt >= 1  && changeStringDayToInt <= 31 && changeStringMonthToInt==1 || changeStringMonthToInt == 3 || changeStringMonthToInt == 5 || changeStringMonthToInt == 7 || changeStringMonthToInt == 8 || changeStringMonthToInt == 10 || changeStringMonthToInt ==12 ) {
                cout << endl << "Date is correct!!" << endl;
                Sleep(1500);
                return true;

            } else if(changeStringDayToInt >= 1 && changeStringDayToInt <= 30 && changeStringMonthToInt == 4 || changeStringMonthToInt == 6 || changeStringMonthToInt == 9 || changeStringMonthToInt == 11) {
                cout << endl << "Date is correct!!" << endl;
                Sleep(1500);
                return true;

            } else if(changeStringDayToInt >= 1 && changeStringDayToInt <= 28 && changeStringMonthToInt==2) {
                cout << endl << "Date is correct!!" << endl;
                Sleep(1500);
                return true;

            } else if(changeStringDayToInt == 29 && changeStringDayToInt == 2) {
                if(isLeapYear(changeStringYearToInt) == true) {
                    cout << endl << "Date is correct!!" << endl;
                    Sleep(1500);
                    return true;

                } else {
                    cout << endl << "Date is wrong!! Enter new date!!" << endl;
                    Sleep(1500);
                    return false;
                }
            } else {
                cout << endl << "Date is wrong!! Enter new date!!" << endl;
                Sleep(1500);
                return false;
            }
        }
    } else {

        cout << endl << "Date is behind range. Enter new date!!" <<endl;
        Sleep(1500);
        return false;
    }
}

int Moneys::takeIdOfNewIncome() {

    int numberOfLastRecipent = 0;
    CMarkup document;

    document.Load("Incomes.xml");
    document.FindElem();
    document.IntoElem();

    while(document.FindElem("DATA")) {
        document.IntoElem();
        document.FindElem("INCOMEID");
        numberOfLastRecipent = atoi(MCD_2PCSZ(document.GetData()));
        document.OutOfElem();
    }
    return numberOfLastRecipent + 1;
}

int Moneys::takeIdOfNewExpense() {

    int numberOfLastRecipent = 0;
    CMarkup document;

    document.Load("Expenses.xml");
    document.FindElem();
    document.IntoElem();

    while(document.FindElem("DATA")) {
        document.IntoElem();
        document.FindElem("EXPENSESID");
        numberOfLastRecipent = atoi(MCD_2PCSZ(document.GetData()));
        document.OutOfElem();
    }
    return numberOfLastRecipent + 1;
}

int Moneys::startOfMonth(int year, int month) {

    string startOfMonth = "";
    int intStartOfMonth = 0;
    string firstDay = "01";

    startOfMonth = convert.convertYearToString(year) + convert.convertMonthToString(month) + firstDay;
    intStartOfMonth = atoi(startOfMonth.c_str());

    return intStartOfMonth;
}

int Moneys::endOfMonth(int year, int month) {

    string endOfMonth = "";
    int intEndOfMonth = 0;

    int numberDaysInMonth = numberOfDaysInMonth(month, year);

    endOfMonth = convert.convertYearToString(year) + convert.convertMonthToString(month) + convert.convertIntToString(numberDaysInMonth);
    intEndOfMonth = atoi(endOfMonth.c_str());

    return intEndOfMonth;

}

void Moneys:: incomesBalance(int startDayOfMonth, int endDayOfMonth) {

    for(vector<Incomes>::iterator itr = incomes.begin(), koniec = incomes.end(); itr != koniec; itr++) {
        if((itr->getDate() >= startDayOfMonth) && (itr->getDate() <= endDayOfMonth)) {

            cout << endl << "Income Id: " << itr-> getIncomeId() << endl;
            cout << "User Id: " << itr->getUserId() << endl;
            cout << "Date: " << convert.addDashToDate(convert.convertIntToString(itr->getDate())) << endl;
            cout << "Item: " << itr->getItem() << endl;
            cout << "Amount: " << itr->getAmount() << endl;

            getch();
        }
    }
}


void Moneys::expensesBalance(int startDayOfMonth, int endDayOfMonth) {

    for(vector<Expenses>::iterator itr = expenses.begin(), koniec = expenses.end(); itr != koniec; itr++) {
        if((itr->getDate() >= startDayOfMonth) && (itr->getDate() <= endDayOfMonth)) {

            cout << endl << "Expense Id: " << itr-> getExpenseId() << endl;
            cout << "User Id: " << itr->getUserId() << endl;
            cout << "Date: " << convert.addDashToDate(convert.convertIntToString(itr->getDate())) << endl;
            cout << "Item: " << itr->getItem() << endl;
            cout << "Amount: " << itr->getAmount() << endl;

            getch();
        }
    }
}

double Moneys::sumOfIncome(int startDayOfMonth,int endDayOfMonth) {

    double incomesSum = 0.0;

    for(vector<Incomes>::iterator itr = incomes.begin(), koniec = incomes.end(); itr != koniec; itr++) {
        if((itr->getDate() >= startDayOfMonth) && (itr->getDate() <= endDayOfMonth)) {

            incomesSum = incomesSum + atof(itr->getAmount().c_str());
        }
    }
    return incomesSum;
}

double Moneys::sumOfExpense(int startDayOfMonth, int endDayOfMonth) {

    double expensesSum = 0.0;

    for(vector<Expenses>::iterator itr = expenses.begin(), koniec = expenses.end(); itr != koniec; itr++) {
        if((itr->getDate() >= startDayOfMonth) && (itr->getDate() <= endDayOfMonth)) {

            expensesSum = expensesSum + atof(itr->getAmount().c_str());
        }
    }
    return expensesSum;
}




