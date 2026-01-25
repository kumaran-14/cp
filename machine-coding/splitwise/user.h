//
// Created by kumaran on 11/3/22.
//

#ifndef CP_MACHINE_CODING_SPLITWISE_USER_H
#define CP_MACHINE_CODING_SPLITWISE_USER_H

#include <bits/stdc++.h>
using namespace std;

class User {
private:
  string userId, name;
public:
  User(string user_id, string user_name);
  string getUserId();
  string getName();
};
#endif // CP_MACHINE_CODING_SPLITWISE_USER_H
