#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mxN 1e7
#define newl cout << "\n"
#define vi vector<int>

typedef pair<int, pair<int, int>> threepair;

class Solution {
public:
  int numberOfSubarrays(vector<int>& arr, k) {
    //Solution 3: Use sliding window to for exact K.
  }
};


int main() {
  auto sol = Solution();
  vector<vector<int>> arr = {{1, 2}, {1, 3}, {2, 3}};
  vector<int> vec = {2,2,2,1,2,2,1,2,2,2};
  int n = arr.size();
  auto res = sol.numberOfSubarrays(vec, 2);
  debug(res);
}

/*
count number of subarray with k distinct elements / k odd numbers / k even numbers

 Solution 1: Convert to 0-1 value array. Then its number of subarrays with sum = k.

   int numberOfSubarrays(vector<int>& arr, int k) {
    int prefixsum = 0;
    int n = arr.size();
    unordered_map<int, int> hm;
    hm[0] = 1;
    int ans = 0;
    for(int i = 0; i < n; i++) {
      prefixsum += arr[i];
      if(hm.find(prefixsum-k) != hm.end()) ans += hm[prefixsum-k];
      hm[prefixsum]++;
    }
    return ans;
  }

 Solution 2: Use no of subarray with at most k distinct elements / k odd numbers / k even numbers / product k / sum k
  This uses sliding window : ans += right_end - left_end + 1; -> derived when you add 1 element where k condition is met.
                             ans += (no of subarrays ending at right_end + single element subarray)
 So using the above basic sliding window for at most k, we can find for exact k as,
 at_most(k) - atmost(k-1);

 Solution for at exactly k distinct numbers/characters in array. (using atmost)
 class Solution {
public:
  int subarraysWithKDistinct(vector<int>& arr, int k) {
    int n = arr.size();
    auto atmostk = [&](int k) {
      int ans = 0, curr = 0, start = 0, end = 0;
      unordered_map<int, int> hm;
      while(end < n) {
        if(hm[arr[end]] == 0) {
          curr++;
        }
        hm[arr[end]]++;
        while(curr > k) {
          if(hm[arr[start]] == 1) curr--;
          hm[arr[start]]--;
          start++;
        }
        ans += end-start+1;
        end++;
      }
      return ans;
    };
    return atmostk(k) - atmostk(k-1);

  }
};


 Solution 3: Use sliding window to for exact K.


 */

