#include "Incomes.h"

Incomes::Incomes() {

incomeId = 0;
userId = 0;
date = 0;
item = "";
amount = "";

}

Incomes::~Incomes() {;}

int Incomes::getIncomeId() {

return incomeId;
}

int Incomes::getUserId() {

return userId;
}

int Incomes::getDate() {

return date;
}

string Incomes::getItem() {

return item;
}

string Incomes::getAmount() {

return amount;
}

void Incomes::setIncomeId(int incomeId) {

this->incomeId = incomeId;
}

void Incomes::setUserId(int userId) {

this->userId = userId;
}

void Incomes::setDate(int date) {

this->date = date;
}

void Incomes::setItem(string item) {

this->item = item;
}

void Incomes::setAmount(string amount) {

this->amount = amount;
}

bool Incomes::operator<(const Incomes& s2) const {

return this->date < s2.date;

}

