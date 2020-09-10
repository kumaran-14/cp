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
  int largestRectangleArea(vector<int>& arr) {
    int ans = 0;
    stack<int> st;
    arr.push_back(-2342);
    int n = arr.size();
    st.push(0);
    for(int i = 1; i < n; i++) {
      // condition will result in 'strictly' increasing order of array
      while(!st.empty() && arr[st.top()] >= arr[i]) {
        auto top = st.top(); st.pop();
        // popped element will be sandwiched between lower height due to strict increasing nature
        int h = arr[top];
        // left border's height will be less than h's height, due to strictly increasing property
        int left = st.empty() ? -1 : st.top();
        // right border's height will be less than h's height, due to while loop entry(i.e enter while loop if curr element is smaller or equal to top of stack(remember stack maintains strictly increasing order)) condition. (this is why dummy node at last is required)
        int right = i;
        ans = max(ans, h*(right-left-1));
      }
      st.push(i);
    }
    return ans;
  }
};
/* This is same concept used in stack. take ith element, find its left border(closest element towards left which is just less than ith height), find right border(closest element in right which is just less than ith height)
 int largestRectangleArea(vector<int>& arr) {
    int ans = 0, n = arr.size();
    if(n == 0) return 0;
    vector<int> lessleft(n, 0), lessright(n, 0);
    lessleft[0] = -1;
    lessright[n-1] = n;
    for(int i = 1; i < n; i++) {
      int idx = i-1;
      while(idx >= 0 && arr[idx] >= arr[i]) idx = lessleft[idx];
      lessleft[i] = idx;
    }

    for(int i = n-2; i >= 0; i--) {
      int idx = i+1;
      while(idx < n && arr[idx] >= arr[i]) idx = lessright[idx];
      lessright[i] = idx;
    }

    for(int i = 0; i < n; i++) {
      int left = lessleft[i];
      int right = lessright[i];
      int h = arr[i];
      ans = max(ans, h*(right-left-1));
    }

    return ans;
  }
 */
int main() {
  auto sol = Solution();
  vector<vector<int>> arr = {{1, 2}, {1, 3}, {2, 3}};
  vector<int> vec = {2, 3, 4};
  int n = arr.size();
//  auto res = sol.largestRectangleArea(vec, );
//  debug(res.size());
  vector<int> v;




}