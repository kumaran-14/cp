//
// Created by kumaran on 11/4/22.
//
#include "percentage_expense.h"
#include "split.h"
#include "percentage_split.h"
#include <vector>

PercentageExpense::PercentageExpense(User * paidby, vector<Split*> splits, double amount):Expense(paidby, splits, amount) {
};
bool PercentageExpense::validate() {
  for(Split* split:getSplits()) {
    if(!dynamic_cast<PercentageSplit*>(split)) return false;
  }
  int currPercentage = 0;
  for(Split* split:getSplits()) {
    PercentageSplit* psplit = dynamic_cast<PercentageSplit*>(split);
    currPercentage += psplit->getPercentage();
  }
  if(currPercentage != 100) return false;
  return true;
}
