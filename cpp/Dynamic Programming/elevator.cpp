int main() {
  fast_io();
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif

  // cses elevator rides, cp book pdf page 113
  ll cap;
  cin >> n >> cap;

  vll weight(n);

  rep(i, 0, n) cin >> weight[i];

  // dp[i] state  = {number of rides, min weight of last ride},
  // where number of bits set in i represents the subset of people who reach the
  // top of the building
  pll dp[1 << n];

  dp[0] = {1, 0};
  rep(mask, 1, (1 << n)) {
    // max value;
    dp[mask] = {4 * n, 0};
    rep(i, 0, n) {
      if (mask & (1 << i)) {
        auto [rides_so_far, min_weight] = dp[mask ^ (1 << i)];
        if (min_weight + weight[i] <= cap) {
          dp[mask] = min(dp[mask], {rides_so_far, min_weight + weight[i]});
        } else {
          dp[mask] = min(dp[mask], {rides_so_far + 1, weight[i]});
        }
      }
    }
  }

  cout << dp[(1 << n) - 1].first;

  return 0;
}