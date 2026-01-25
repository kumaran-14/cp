//
// Created by kumaran on 11/4/22.
//
#include "exact_split.h"

ExactSplit::ExactSplit(User *user, double amount):Split(user) {
  this->amount = amount;
}
