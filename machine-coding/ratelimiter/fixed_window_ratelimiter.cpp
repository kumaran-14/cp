//
// Created by kumaran on 11/5/22.
//

#include "fixed_window_ratelimiter.h"
#include <bits/stdc++.h>
#include <chrono>
#include <mutex>
using namespace std;
using namespace chrono;

mutex mtx;

FixedWindowRateLimiter::FixedWindowRateLimiter(int mx, int exp) {
  this->max_req = mx;
  this->expiry_time = exp;
}

bool FixedWindowRateLimiter::rateLimit(int id) {
  mtx.lock();
  if()

}
