    #include<bits/stdtr1c++.h>
    using namespace std;
    typedef long long int ll;
    const int MAX = 3e5+5;
    const int INF = 1e8;
    vector<int>v[MAX];
    int maxi[MAX],mini[MAX],val[MAX];
    bool visit[MAX];
    pair<int,pair<int,int> > edges[MAX];
     
    void DFS(int node,int w)
    {
      if(visit[node])
        return ;
     
      visit[node]=true;
      val[node]=w;
      for(int i = 0 ; i < v[node].size() ; i++)
      {
          DFS(v[node][i],w);
      }
    }
     
    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n,m,x,y,w;
        cin>>n>>m;
        for(int i = 1 ; i <=  m ; i++)
        {
            cin>>x>>y>>w;
            v[x].push_back(y);
            edges[i].first = w;
            edges[i].second = make_pair(x,y);
        }
        sort(edges+1,edges+m+1);
        for(int i = 1 ; i<= n ; i++)
            val[i]=INF,visit[i]=false;
        for(int i = 1 ; i <= m ; i++)
        {
            DFS(edges[i].second.second,edges[i].first);
        }
        for(int i = 1 ; i <= n ; i++)
            mini[i]=val[i],val[i]=-INF,visit[i]=false;
        for(int i = m ; i>= 1 ; i--)
        {
            DFS(edges[i].second.second,edges[i].first);
        }
        for(int i = 1 ; i <= n ; i++)
           maxi[i]=val[i];
        int res = 0;
        for(int i = 1 ; i <= m ; i++)
        {
            int x = edges[i].second.first;
            if(mini[x]!=INF)
                res = max(res , edges[i].first - mini[x]);
            if(maxi[x]!=-INF)
                res = max(res , maxi[x] - edges[i].first);
        }
     
        cout << res <<endl;
     
    }