// https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/fight-for-laddus/

#include <iostream>
#include <bits/stdc++.h>
#define l long

using namespace std;

int main()
{
  int tc;
  cin >> tc; // Reading input from STDIN
  for (int j = 0; j < tc; ++j)
  {
    l size;
    cin >> size;
    l arr[size];
    for (l i = 0; i < size; ++i)
    {
      cin >> arr[i];
    }
    unordered_map<l, l> mp;
    for (l i = 0; i < size; i++)
      mp[arr[i]]++;
    l carr[size];
    for (l i = 0; i < size; ++i)
    {
      carr[i] = mp[arr[i]];
    }
    // stack operations
    stack<l> s;
    s.push(0);
    for (int i = 1; i < size; ++i)
    {
      if (s.empty())
      {
        s.push(i);
        continue;
      }
      while (s.empty() == false && carr[s.top()] < carr[i])
      {
        arr[s.top()] = arr[i];
        s.pop();
      }
      s.push(i);
    }
    while (s.empty() == false)
    {
      arr[s.top()] = -1;
      s.pop();
    }
    for (auto x : arr)
    {
      cout << x << " ";
    }
    cout << endl;
  }
  return 0;
}
