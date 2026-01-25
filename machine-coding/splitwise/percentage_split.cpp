//
// Created by kumaran on 11/4/22.
//

#include "percentage_split.h"

PercentageSplit::PercentageSplit(User * user, int percentage): Split(user) {
  this->percentage = percentage;
}

int PercentageSplit::getPercentage() {
  return this->percentage;
}
