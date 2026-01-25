//
// Created by kumaran on 11/4/22.
//

#ifndef CP_MACHINE_CODING_SPLITWISE_EXPENSE_H
#define CP_MACHINE_CODING_SPLITWISE_EXPENSE_H



#include "user.h"
#include "split.h"
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

class Expense {
private:
  User* paidby;
  double amount;
  bool settled;
protected:
  vector<Split*> splits;

public:
  Expense(User*, vector<Split*>, double);
  vector<Split*> getSplits();
  double getAmount();
  virtual bool validate() = 0;
};

#endif // CP_MACHINE_CODING_SPLITWISE_EXPENSE_H
