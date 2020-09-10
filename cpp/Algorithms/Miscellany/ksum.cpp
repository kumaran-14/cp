class Solution {
public:
  // without duplicates
  vector<vector<int>> fourSum(vector<int>& arr, int target) {

    vector<vector<int>> ans;

    // two sum;

    auto twosum = [&](int left, int right, int need, vector<int> sol) {
      while(left < right) {
        while(left < right && arr[left] == arr[left+1]) left++;
        while(left < right && arr[right] == arr[right-1]) right--;
        int sum = arr[left] + arr[right];
        debug(sum);
        if(sum == need) {
          // found {left, right};;
          sol.push_back(arr[left]);
          sol.push_back(arr[right]);
          ans.push_back(sol);
          sol.pop_back();
          sol.pop_back();
          left++;
          right--;
        } else if(sum < need) {
          left++;
        } else {
          right--;
        }
      }
    };

    // k sum;
    function<void(int, int, int, int, vector<int>)> ksum = [&](int k, int left, int right, int need, vector<int> sol) {
      if(k == 2) twosum(left, right, need, sol);
      else {
        while(left < right && arr[left] == arr[left+1]) left++;
        sol.push_back(arr[left]);
        ksum(k-1, left+1, right, need-arr[left], sol);
      }
    };
    vector<int> sol;
    ksum(3, 0, arr.size()-1, target, sol);
    for(auto x:ans) {
      for(auto y:x) cout<<y<<" ";
      newl;
    }

    return ans;
  }
};