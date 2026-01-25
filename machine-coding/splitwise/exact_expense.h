//
// Created by kumaran on 11/4/22.
//

#ifndef CP_MACHINE_CODING_SPLITWISE_EXACT_EXPENSE_H
#define CP_MACHINE_CODING_SPLITWISE_EXACT_EXPENSE_H

#include "user.h"
#include "expense.h"
#include "split.h"
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

class ExactExpense : public Expense {
public:
  ExactExpense(User*, vector<Split*>, double);
  bool validate();
};

#endif // CP_MACHINE_CODING_SPLITWISE_EXACT_EXPENSE_H
