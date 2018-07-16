#include "Convert.h"

Convert::Convert() {;}

Convert::~Convert() {;}

int Convert::convertStringToInt(string tempDate) {

    int intDate = 0;
    intDate = atoi(tempDate.c_str());

    return intDate;

}

string Convert::convertCommaToDot(string amount) {

int i = 0;
    int length = amount.length();

    while(i < length) {

        if(amount[i] == ',') {

            amount[i] = '.';
            break;
        }
        i++;
    }
    return amount;
}

string Convert::convertDayToString(int day) {

const string zero = "0";
    string stringDay;
    string dayy;

    if((day >= 1) && (day <= 9)) {

        stringstream ss;
        ss << day;
        dayy = ss.str();

        stringDay = zero + dayy;

        return stringDay;
    } else {

        stringstream ss;
        ss << day;
        stringDay = ss.str();

        return stringDay;
    }
}

string Convert::convertMonthToString(int month) {

const string zero = "0";
    string stringMonth;
    string monthh;

    if((month >= 1) && (month <= 9)) {

        stringstream ss;
        ss << month;
        monthh = ss.str();

        stringMonth = zero + monthh;

        return stringMonth;
    } else {

        stringstream ss;
        ss << month;
        stringMonth = ss.str();

        return stringMonth;
    }
}

string Convert::convertYearToString(int year) {

const string zero = "0";
    string stringYear;
    string yearr;

    stringstream ss;
    ss << year;
    stringYear = ss.str();

    return stringYear;
}

string Convert::convertIntToString(int numberDaysInMonth) {

ostringstream ss;
    ss << numberDaysInMonth;
    return ss.str();
}

string Convert::spreadYear(string date) {

int length = date.length();
    int i = 0;
    string year = "";

    while(i < length) {

        if((date[i] != '-') && (i < 5)) {

            year = year + date[i];
        }
        i++;
    }
    return year;
}

string Convert::spreadMonth(string date) {

int length = date.length();
    int i = 0;
    string month = "";

    while(i < length) {

        if((date[i] != '-') && (i >= 5) && (i < 8)) {

            month = month + date[i];
        }
        i++;
    }
    return month;
}

string Convert::spreadDay(string date) {

int length = date.length();
    int i = 0;
    string day = "";

    while(i < length) {

        if((date[i] != '-') && (i >= 8)) {

            day = day + date[i];
        }
        i++;
    }
    return day;
}

string Convert::nameOfMonth(int month) {

string nameOfMonth = "";

    if(month == 1) {
        nameOfMonth = "January";
    } else if(month == 2) {
        nameOfMonth = "February";
    } else if(month == 3) {
        nameOfMonth = "March";
    } else if(month == 4) {
        nameOfMonth = "April";
    } else if(month == 5) {
        nameOfMonth = "May";
    } else if(month == 6) {
        nameOfMonth = "June";
    } else if(month == 7) {
        nameOfMonth = "July";
    } else if(month == 8) {
        nameOfMonth = "August";
    } else if(month == 9) {
        nameOfMonth = "September";
    } else if(month == 10) {
        nameOfMonth = "October";
    } else if(month == 11) {
        nameOfMonth = "November";
    } else if(month == 12) {
        nameOfMonth = "December";
    }

    return nameOfMonth;
}

string Convert::addDashToDate(string date) {

int length = date.length();
    int i = 0;
    string dash = "-";
    string year = "";
    string month = "";
    string day = "";

    while(i < length) {

        if(i < 4) {

            year = year + date[i];
        } else if ((i > 3) && (i < 6)) {

            month = month + date[i];
        } else if (i > 5) {

            day = day + date[i];
        }
        i++;
    }
    year = year + dash;
    month = month + dash;

    date = year + month + day;

    return date;
}
