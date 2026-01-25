//
// Created by kumaran on 11/4/22.
//

#ifndef CP_MACHINE_CODING_SPLITWISE_PERCENTAGE_SPLIT_H
#define CP_MACHINE_CODING_SPLITWISE_PERCENTAGE_SPLIT_H

#include "split.h"
#include "user.h"
#include <bits/stdc++.h>
using namespace std;

class PercentageSplit: public Split {
private:
  int percentage;
public:
  PercentageSplit(User*, int);
  int getPercentage();
};

#endif // CP_MACHINE_CODING_SPLITWISE_PERCENTAGE_SPLIT_H
