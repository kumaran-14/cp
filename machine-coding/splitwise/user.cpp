//
// Created by kumaran on 11/3/22.
//
#include "user.h"


User::User(string user_id, string user_name): userId(user_id), name(user_name){}
string User::getUserId() {
  return this->userId;
}
string User::getName() {
  return this->name;
}

