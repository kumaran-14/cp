//
// Created by kumaran on 11/5/22.
//

#ifndef CP_MACHINE_CODING_RATELIMITER_RATELIMITER_H
#define CP_MACHINE_CODING_RATELIMITER_RATELIMITER_H

#include <bits/stdc++.h>
using namespace std;

class IRateLimiter {
public:
  virtual bool rateLimit(int) = 0;
};


#endif // CP_MACHINE_CODING_RATELIMITER_RATELIMITER_H
