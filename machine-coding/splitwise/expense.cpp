//
// Created by kumaran on 11/4/22.
//
#include "expense.h"

Expense::Expense(User * paidby, vector<Split*> splits, double amount) {
  this->paidby = paidby;
  this->splits = splits;
  this->amount = amount;
  this->settled = false;
}

double Expense::getAmount() {
  return this->amount;
}

vector<Split*> Expense::getSplits() {
    return this->splits;
}
