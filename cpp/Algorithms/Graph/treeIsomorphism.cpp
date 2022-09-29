
ll tc, n, m, k;
const ll mxN = 1e5 + 7;


int main() {
  fast_io();
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif

  // https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=936
  cin>>n;
  while(n--) {
    string s1, s2; cin>>s1>>s2;
    vll g1[mxN];
    vll g2[mxN];

    ll u = 1;
    ll v = 2;

    stack<ll> st;
    st.push(u);
    rep(j, 0, sz(s1)) {
      if(s1[j] == '0') {
        u = st.top();
        g1[u].pb(v);
        g1[v].pb(u);
        st.push(v++);
      } else {
        st.pop();
      }
    }
    while(!st.empty()) st.pop();
    u = 1;
    v = 2;
    st.push(u);
    rep(j, 0, sz(s2)) {
      if(s2[j] == '0') {
        u = st.top();
        g2[u].pb(v);
        g2[v].pb(u);
        st.push(v++);
      } else {
        st.pop();
      }
    }
    vector<string> dp1(v);
    vector<string> dp2(v);


    // Aho-Hopcroft-Ullman tree isomorphism invariant algorithm
    // find canoical form(string representation of rooted tree)
    // main algo start
    function<void(ll, ll)> dfs1 = [&](ll u, ll p) {
      dp1[u].pb('0');
      vector<string> vstrs;
      for(auto v:g1[u]) {
        if(v == p) continue;
        dfs1(v, u);
        vstrs.pb(dp1[v]);
      }
      sort(all(vstrs));
      // sorting makes is canonical
      for(auto ss:vstrs) dp1[u] += ss;
      dp1[u].pb('1');
    };
    // main algo end
    // algo explained here: https://logic.pdmi.ras.ru/~smal/files/smal_jass08_slides.pdf

    function<void(ll, ll)> dfs2 = [&](ll u, ll p) {
      dp2[u].pb('0');
      vector<string> vstrs;
      for(auto v:g2[u]) {
        if(v == p) continue;
        dfs2(v, u);
        vstrs.pb(dp2[v]);

      }
      sort(all(vstrs));
      for(auto ss:vstrs) dp2[u] += ss;
      dp2[u].pb('1');
    };


    dfs1(1, 1);
    string str1 = dp1[1];

    dfs2(1, 1);
    string str2 = dp2[1];
    if(str1 == str2) {
      cout<<"same";
    } else {
      cout<<"different";
    }
    newl;
  }

  return 0;
}
