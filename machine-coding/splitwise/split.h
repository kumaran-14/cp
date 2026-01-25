//
// Created by kumaran on 11/3/22.
//

#ifndef CP_MACHINE_CODING_SPLITWISE_SPLIT_H
#define CP_MACHINE_CODING_SPLITWISE_SPLIT_H




#include "user.h"
#include <bits/stdc++.h>
using namespace std;

class Split {
private:
  User *user;

protected:
  double amount;
public:
  Split(User*);
  User* getUser();
  int getAmount();
  void setAmount(double);
  virtual ~Split();
};

#endif // CP_MACHINE_CODING_SPLITWISE_SPLIT_H
