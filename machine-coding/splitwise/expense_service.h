//
// Created by kumaran on 11/4/22.
//

#ifndef CP_MACHINE_CODING_SPLITWISE_EXPENSE_SERVICE_H
#define CP_MACHINE_CODING_SPLITWISE_EXPENSE_SERVICE_H


#include "user.h"
#include "expense.h"
#include "split.h"
#include <bits/stdc++.h>
using namespace std;

enum ExpenseType {
  EQUAL
  EXACT
  PERCENTAGE
};

class ExpenseService {
public:
  static Expense* createExpense( ExpenseType expenseType,
      User* paidby,
      double amount,
      vector<Split*> splits);
};

#endif // CP_MACHINE_CODING_SPLITWISE_EXPENSE_SERVICE_H
