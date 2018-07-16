#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include "Incomes.h"
#include <vector>
#include "Markup.h"


using namespace std;

class IncomesFile {

string nameOfSaveIncomes;

public:
    IncomesFile();
    virtual ~IncomesFile();
    void saveFirstIncome(Incomes income);
    void saveNextIncomes(Incomes income);
    void loadIncomesToVector(vector<Incomes> &incomes, int loggedInUserId);


};




#endif // INCOMESFILE_H
