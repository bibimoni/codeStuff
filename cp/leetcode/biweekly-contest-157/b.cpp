#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxSubstrings(string s) {
    int n = s.size();
    vector<vector<int>> last(n, vector<int>(26, -1));
    vector<vector<int>> prev(n, vector<int>(26, -1));
    for (int c = 0; c < 26; c++) {
      for (int i = 0; i < n; i++) {
        if (c == s[i] - 'a') {
          last[i][c] = i;
        } else if (i - 1 >= 0) {
          last[i][c] = last[i - 1][c];
        }

        if (i - 3 >= 0) {
          prev[i][c] = last[i - 3][c];
        }
      }
    }
    // for (int i = 0; i < n; i++) {
    //   cout << prev[i][s[i] - 'a'] << " \n"[i == n - 1];
    // }
    vector<int> dp(n + 1);
    for (int i = 3; i < n; i++) {
      dp[i + 1] = dp[i];
      if (prev[i][s[i] - 'a'] >= 0) {
        dp[i + 1] = max(dp[i + 1], dp[prev[i][s[i] - 'a']] + 1);
      }
    }
    return dp[n];
  }
};
