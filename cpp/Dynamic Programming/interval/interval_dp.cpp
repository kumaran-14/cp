

int main() {
  fast_io();
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif

  // UVA 662 Fast Food
  // https://blog.csdn.net/u013582254/article/details/45922345?utm_medium=distribute.pc_relevant.none-task-blog-OPENSEARCH-14.control&dist_request_id=&depth_1-utm_source=distribute.pc_relevant.none-task-blog-OPENSEARCH-14.control
  ll c = 1;
  while (cin >> n >> k && n && k) {
    ll ans = inf;

    vll pos(n + 1, 0);

    rep(i, 1, n + 1) cin >> pos[i];

    vvll dist(n + 1, vll(n + 1, 0));
    rep(i, 1, n + 1) {
      rep(j, i, n + 1) {
        for (int x = i; x <= j; x++) {
          dist[i][j] += abs(pos[x] - pos[(i + j) / 2]);
        }
      }
    }
    vvll dp(n + 1, vll(k + 1, inf));
    vvll path(n+1, vll(n+1, 0));

    rep(i, 1, n + 1) {
      dp[i][1] = dist[1][i];
      path[1][i] = 0;
    }


    /*
      choose 1 restaurant as warehouse from restaurants between i and j
      = choose middle one, (i+j)/2;
     */

    /*
      dp[10][4], 4 warehouses from first 10 restaurants
      = min of all these below
      = 3 warehouses from first 3 restaurants + cost to choose middle restaurant as warehouse from remaining 7 restaurants
      = ..
      = ..
      = 3 warehouses from first 9 restaurants + cost to choose middle restaurant as warehouse from remaining 1 restaurant

     */
    rep(i, 1, n + 1) {
      rep(j, 2, k + 1) {
        for (int p = j - 1; p < i; p++) {
          if(dp[p][j-1] + dist[p+1][i] < dp[i][j]) {
            dp[i][j] = min(dp[i][j], dp[p][j - 1] + dist[p + 1][i]);
            path[i][j] = p;
          }
        }
      }
    }

    function<void(ll a, ll b)> dfs = [&](ll n, ll k) {
      if(k <= 0) return;
      dfs(path[n][k], k-1);
      ll depotid = k;
      ll restid = (path[n][k]+1+n)/2;
      ll left = path[n][k]+1;
      ll right = n;
      if(left == right) {
        cout<<"Depot "<<depotid<<" at restaurant "<<restid<<" serves restaurant "<<left<<"\n";
      } else {
        cout<<"Depot "<<depotid<<" at restaurant "<<restid<<" serves restaurants "<<left<<" to "<<right<<"\n";
      }
    };


    cout << "Chain " << c;
    newl;
    dfs(n, k);
    cout << "Total distance sum = " << dp[n][k];
    c++;
    newl;
    newl;
  }

  return 0;
}