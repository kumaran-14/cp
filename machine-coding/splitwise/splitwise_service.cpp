//
// Created by kumaran on 11/4/22.
//

#include "splitwise_service.h"
#include "expense_service.h"
void Splitwise::addUser(User *user) {
  this->userMap[user->getUserId()] = user;
}
User * Splitwise::getUser(int userId) {
  return this->userMap[userId];
}

void Splitwise::addExpense(ExpenseType expenseType, double amount, string paidby, vector<Split*> splits) {
  Expense* expense = ExpenseService::createExpense(expenseType, Splitwise::getUser(paidby), splits);
  if(expense->validate()) {
    this->expenses.push_back(expense)
  } else {
    throw new exception();
  }
  for(Split* split:splits) {
    string paidfor = split->getUser()->getUserId();
    if(this->balancesheet[paidby].find(paidfor) == this->balancesheet[paidby].end()) {
      this->balancesheet[paidby][paidfor] = 0.0;
    }
    this->balancesheet[paidby][paidfor] += split->getAmount();
    if(this->balancesheet[paidfor].find(paidby) == this->balancesheet[paidfor].end()) {
      this->balancesheet[paidfor][paidby] = 0.0;
    }
    this->balancesheet[paidfor][paidby] -= split->getAmount();
  }
}

void SplitWise::showBalance(string userId){

  if(balancesheet[userId].size() == 0){
    cout<<"No pending expenses for this user\n";
  }
  for(auto balance: balancesheet[userId]){
    if(balance.second > 0)
      cout<<"User "<<balance.first<<" owes user "<<userId<<" amount "<<balance.second<<"\n";
    else
      cout<<"User "<<userId<<" owes user "<<balance.first<<" amount "<<-1*balance.second<<"\n";
  }
}

void Splitwise::settleBalance(string userid1, string userid2) {
  this->balancesheet[userid1].erase(userid2);
  this->balancesheet[userid2].erase(userid1);
}

