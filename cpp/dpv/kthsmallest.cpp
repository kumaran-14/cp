// Divide and Conquer, Kth smallest or median of array in O(n). Better than min or max heap method.

#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())

  int kthsmallest(vector<int> vec, int k) {
    random_device rd; // obtain a random number from hardware
    mt19937 eng(rd()); // seed the generator
    uniform_int_distribution<> distr(0, sz(vec)-1);
    vector<int> sl, sv, sr;
    int randval = distr(eng);
    cout << " Size of vec: " << sz(vec)<<endl;
    cout << " Random number index: " << randval << " " << vec[randval] << endl;
    for (auto x : vec)
    {
      if(x > vec[randval])
        sr.push_back(x);
      else if(x == vec[randval])
        sv.push_back(x);
      else if(x < vec[randval])
        sl.push_back(x);
    }
    if (k <= sz(sl))
      return kthsmallest(sl, k);
    else if( k > sz(sl) && k <= sz(sl) + sz(sv))
      return vec[randval];
    else if( k > sz(sl) + sz(sv))
      return kthsmallest(sr, k - sz(sl) -sz(sv));
  }

  int main()
  {

    vector<int> vec = {2, 36, 5, 21, 8, 13, 11, 20, 5, 4, 1};
    int k = 10;
    int kthsmallestEl = kthsmallest(vec, k);
    cout << kthsmallestEl << endl;
  }
