//
// Created by kumaran on 11/4/22.
//

#include "expense_service.h"
#include "exact_expense.h"
#include "percentage_expense.h"
Expense * ExpenseService::createExpense(ExpenseType expenseType, User *paidby, double amount, int splits) {
  switch(expenseType) {
    case ExpenseType::EXACT: {
      return new ExactExpense(paidby, splits, amount);
      break;
    }
    case ExpenseType::PERCENTAGE: {
      for(Split* split: splits) {
        PercentageSplit* psplit = static_cast<PercentageSplit*>(split);
        psplit->setAmount((amount*pslit->getPercentage())/100.0)
      }
      return new PercentageExpense(paidby, splits, amount);
      break;
    };
  }
}
