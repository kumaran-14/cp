//
// Created by kumaran on 11/4/22.
//
#include "exact_expense.h"
#include "exact_split.h"

ExactExpense::ExactExpense(User * paidby, vector<Split*> splits, double amount):Expense(paidby, splits, amount) {}

bool ExactExpense::validate() {
  for(Split* split: getSplits()) {
    if(!down_cast<ExactSplit*>(split)) return false;
  }
  double currtotal = 0;
  for(Split* split: getSplits()) {
    ExactSplit* esplit = down_cast<ExactSplit*>(split);
    currtotal += esplit->getAmount();
  }
  if(currtotal != getAmount()) return false;
  return true;
}
