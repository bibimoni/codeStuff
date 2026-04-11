#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<string> partitionString(string s) {
    vector<string> ans;
    vector<int> cnt(26);
    vector<int> cur(26);
    string t = "";
    for (char c : s) {
      t += c;
      if (cur[c - 'a'] + 1 > cnt[c - 'a']) {
        cnt[c - 'a'] += 1;
        ans.push_back(t);
        t = "";
        cur = vector<int>(26);
      } else {
        cur[c - 'a'] += 1;
      }
    }
    return ans;
  }
};
