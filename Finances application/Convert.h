#include <iostream>
#include "Moneys.h"

#ifndef CONVERT_H
#define CONVERT_H

class Convert{

public:
    Convert();
    virtual ~Convert();
    int convertStringToInt(string tempDate);
    string convertCommaToDot(string amount);
    string convertDayToString(int day);
    string convertMonthToString(int month);
    string convertYearToString(int year);
    string convertIntToString(int numberDaysInMonth);
    string spreadYear(string date);
    string spreadMonth(string date);
    string spreadDay(string date);
    string nameOfMonth(int month);
    string addDashToDate(string date);

};



#endif // CONVERSION_H
