//
// Created by kumaran on 11/4/22.
//

#ifndef CP_MACHINE_CODING_SPLITWISE_SPLITWISE_SERVICE_H
#define CP_MACHINE_CODING_SPLITWISE_SPLITWISE_SERVICE_H

#include <iostream>
#include "expense.hpp"
#include <vector>
#include <unordered_map>
#include "expense_service.h"
#include <bits/stdc++.h>
using namespace std;

class Splitwise {
private:
  vector<Expense*> expenses;
  unordered_map<string, User*> userMap;
  unordered_map<string, unordered_map<string, double>> balancesheet;
public:
  void addUser(User*);
  void addExpense(ExpenseType, double, string, vector<Split*> splits);
  void showBalances();
  void showBalances(string);
  void settleBalance(string, string);
  User* getUser(string userId);
};

#endif // CP_MACHINE_CODING_SPLITWISE_SPLITWISE_SERVICE_H
