// kumaran_14
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    long long int n, m;
    cin >> n >> m;
    long long int c[m], i, d[n], f[n], b[n], a[n], sum = 0, k;

    for (i = 0; i < m; i++)
      cin >> c[i];

    for (i = 0; i < n; i++)
    {
      cin >> d[i] >> f[i] >> b[i];
      if (c[d[i] - 1] > 0)
      {
        c[d[i] - 1]--;
        a[i] = d[i];
        sum = sum + f[i];
      }
      else
      {
        a[i] = 0;
        sum = sum + b[i];
      }
    }
    for (k = 0; k < n; k++)
    {
      if (a[k] == 0)
      {
        for (i = 0; i < m; i++)
        {
          if (c[i] > 0)
          {
            c[i]--;
            a[k] = i + 1;
            break;
          }
        }
      }
    }
    cout << sum << endl;
    for (i = 0; i < n; i++)
    {
      cout << a[i] << " ";
    }
    cout << endl;
  }
}
