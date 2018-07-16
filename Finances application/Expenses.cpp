#include "Expenses.h"

Expenses::Expenses() {

expenseId = 0;
userId = 0;
date = 0;
item = "";
amount = "";
}

Expenses::~Expenses() {;}

int Expenses::getExpenseId() {

return expenseId;
}

int Expenses::getUserId() {

return userId;
}

int Expenses::getDate() {

return date;
}

string Expenses::getItem() {

return item;
}

string Expenses::getAmount() {

return amount;
}

void Expenses::setExpenseId(int expenseId) {

this->expenseId = expenseId;
}

void Expenses::setUserId(int userId) {

this->userId = userId;
}

void Expenses::setDate(int date) {

this->date = date;
}

void Expenses::setItem(string item) {

this->item = item;
}

void Expenses::setAmount(string amount) {

this->amount = amount;
}

bool Expenses::operator<(const Expenses& s2) const {

return this->date < s2.date;

}


