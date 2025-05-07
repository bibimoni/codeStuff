// time-limit: 3000
/**
 * Author: distiled
 */
#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
#define int int64_t 

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> s(n);
  int m = 0;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    m = max(m, int(s[i].size()));
  }
  vector<vector<char>> ans(m, vector<char>(n, '*'));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < s[i].size(); j++) {
      ans[j][n - i - 1] = s[i][j];  
    }
  }
  for (int i = 0; i < m; i++) {
    while (ans[i].back() == '*') {
      ans[i].pop_back();
    }
    for (char c : ans[i]) {
      cout << c;
    }
    cout << '\n';
  }
}


