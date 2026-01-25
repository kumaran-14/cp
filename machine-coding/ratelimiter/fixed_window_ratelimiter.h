//
// Created by kumaran on 11/5/22.
//

#ifndef CP_MACHINE_CODING_RATELIMITER_FIXED_WINDOW_RATELIMITER_H
#define CP_MACHINE_CODING_RATELIMITER_FIXED_WINDOW_RATELIMITER_H

#include "ratelimiter.h"

class FixedWindowRateLimiter: public IRateLimiter {
private:
  int max_req;
  long expiry_time;
  unordered_map<int, pair<int, long>>
public:
  FixedWindowRateLimiter(int, int);
  bool rateLimit(int id);
};


#endif // CP_MACHINE_CODING_RATELIMITER_FIXED_WINDOW_RATELIMITER_H
