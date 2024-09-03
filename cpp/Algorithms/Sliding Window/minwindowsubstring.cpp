#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int left =  0;
        int right = 0;
        int tcounter = m;
        int start = 0;
        int len = INT_MAX;
        unordered_map<char, int> thm;
        for(auto ch:t) thm[ch]++;
        while(right < n) {
            if(thm[s[right]] > 0) tcounter--;
            thm[s[right]]--;
            // increasing window
            right++;
            // window now consist of all ch of 't' and possibly more.
            while(tcounter == 0){
                if(right-left < len) {
                    len = min(len, right-left);
                    start = left;
                }

                // removing ch from window
                thm[s[left]]++;
                // removed ch exists in 't'. It is > 0 as initially all ch in t were counted by occurence.
                if(thm[s[left]] > 0) tcounter++;
                // decreasing window
                left++;
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};