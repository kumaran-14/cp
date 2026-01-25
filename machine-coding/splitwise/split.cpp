//
// Created by kumaran on 11/3/22.
//

#include "split.h"

Split::Split(User *user) {
  this->user = user;
}
Split::~Split(){}

User * Split::getUser() {
  return this->user;
}

int Split::getAmount() {
  return this->amount;
}
void Split::setAmount(double amount) {
  this->amount = amount;
}

