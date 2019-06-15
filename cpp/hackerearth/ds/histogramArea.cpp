// https://www.hackerrank.com/challenges/largest-rectangle/problem
#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define foi(i, a, n) for (i = (a); i < (n); ++i)
#define foii(i, a, n) for (i = (a); i <= (n); ++i)
#define fod(i, a, n) for (i = (a); i > (n); --i)
#define fodd(i, a, n) for (i = (a); i >= (n); --i)
#define gcd __gcd
#define mem(a, b) memset(a, b, sizeof a)
#define all(v) v.begin(), v.end()
#define println(a) cout << (a) << endl
#define sz(x) ((int)(x).size())
#define readi(x) scanf("%d", &x)
#define read2i(x, y) scanf("%d%d", &x, &y)
#define read3i(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define PI 3.141592653589793238L
#define MOD 1000000007LL
#define EPS 1e-13
#define INFI 1000000000
#define INFLL 1000000000000000000ll

#define l long int
#define d double
#define ll long long
#define ld long double
#define vi vector<int>
#define vs vector<string>
#define vc vector<char>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define si set<int>
#define mii map<int, int>
#define mll map<long long, long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pil pair<int, long long>
#define pli pair<long long, int>
#define pcc pair<char, char>
#define pdd pair<double, double>

vector<string> split_string(string);

// Complete the largestRectangle function below.
// 1st Method: Find the width for each height. Find max area by calculating width * height;
// 2nd Method: Use stack;

// long largestRectangle(vector<int> h)
// {
//   vi range(sz(h), 1);
//   ll i, j;
//   ll width;
//   foi(i, 0, sz(h))
//   {
//     width = 0;
//     j = i;
//     while (j < sz(h) && h[i] <= h[j])
//     {
//       width++;
//       j++;
//     }
//     j = i - 1;
//     while (j >= 0 && h[i] <= h[j])
//     {
//       width++;
//       j--;
//     }
//     range[i] = width;
//   }
//   ll max = 0;
//   foi(i, 0, sz(range))
//   {
//     if (max < h[i] * range[i])
//       max = h[i] * range[i];
//   }
//   return max;
// }

long largestRectangle(vector<int> h)
{
  stack<int> stindex;
  ll maxar = 0;
  ll i;
  foi(i, 0, sz(h))
  {
    if (stindex.empty() || h[stindex.top()] <= h[i])
    {
      stindex.push(i);
      continue;
    }
    while (!stindex.empty() && h[stindex.top()] > h[i])
    {
      int maxindex = stindex.top();
      stindex.pop();
      maxar = max(maxar, h[maxindex] * (stindex.empty() ? (i) : (i - 1 - stindex.top())));
    }
    stindex.push(i);
  }
  while (!stindex.empty())
  {
    int maxindex = stindex.top();
    stindex.pop();
    maxar = max(maxar, h[maxindex] * (stindex.empty() ? (i) : (i - 1 - stindex.top())));
  }

  return maxar;
}

int main()
{
  ofstream fout(getenv("OUTPUT_PATH"));

  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string h_temp_temp;
  getline(cin, h_temp_temp);

  vector<string> h_temp = split_string(h_temp_temp);

  vector<int> h(n);

  for (int i = 0; i < n; i++)
  {
    int h_item = stoi(h_temp[i]);

    h[i] = h_item;
  }

  long result = largestRectangle(h);

  fout << result << "\n";

  fout.close();

  return 0;
}

vector<string> split_string(string input_string)
{
  string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
    return x == y and x == ' ';
  });

  input_string.erase(new_end, input_string.end());

  while (input_string[input_string.length() - 1] == ' ')
  {
    input_string.pop_back();
  }

  vector<string> splits;
  char delimiter = ' ';

  size_t i = 0;
  size_t pos = input_string.find(delimiter);

  while (pos != string::npos)
  {
    splits.push_back(input_string.substr(i, pos - i));

    i = pos + 1;
    pos = input_string.find(delimiter, i);
  }

  splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

  return splits;
}
