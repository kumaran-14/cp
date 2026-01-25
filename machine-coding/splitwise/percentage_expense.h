//
// Created by kumaran on 11/4/22.
//

#ifndef CP_MACHINE_CODING_SPLITWISE_PERCENTAGE_EXPENSE_H
#define CP_MACHINE_CODING_SPLITWISE_PERCENTAGE_EXPENSE_H
#include "expense.h"
#include "user.h"
#include "split.h"
#include <bits/stdc++.h>
using namespace std;

class PercentageExpense: public Expense {
public:
  PercentageExpense(User*, vector<Split*>, double amount);
  bool validate();
};


#endif // CP_MACHINE_CODING_SPLITWISE_PERCENTAGE_EXPENSE_H
