//
// Created by kumaran on 11/4/22.
//

#ifndef CP_MACHINE_CODING_SPLITWISE_EXACT_SPLIT_H
#define CP_MACHINE_CODING_SPLITWISE_EXACT_SPLIT_H


#include "split.h"
#include "user.h"
#include <bits/stdc++.h>
using namespace std;

class ExactSplit: public Split {
public:
  ExactSplit(User* user, double amount);
};


#endif // CP_MACHINE_CODING_SPLITWISE_EXACT_SPLIT_H
