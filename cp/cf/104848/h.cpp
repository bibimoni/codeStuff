/**
 * Author: distiled
 */
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#define table(...)
#endif
// #define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  s = " " + s;
  const int inf = 1e9;
  vector<int> dp(n + 1, inf);
  dp[0] = 0;
  auto ok= [&](int i, int j) -> bool {
    string t = s.substr(i, j - i + 1); 
    bool same = true;
    for (char c : t) {
      same &= c == t[0];
    }
    return 
      (same && (t[0] != 'V' && t[0] != 'L' && t[0] != 'D'))
      || t == "MCM"
      || t == "CXC"
      || t == "XIX"
      || j - i == 0;
  };

  vector<int> trace(n + 1, -1);
  for (int i = 1; i <= n; i++) {
    for (int j = i - 1; j >= max(i - 3, 0); j--) {
      if (!ok(j + 1, i) || dp[j] == inf) {
        continue; 
      } 

      if (dp[i] > dp[j] + 1) {
        dp[i] = dp[j] + 1;
        trace[i] = j;
      }
    }
  }
  table(dp);

  cout << dp[n] << "\n";
  vector<string> ans;
  int cur = n;
  while (cur != 0) {
    int nxt = trace[cur];
    ans.push_back(s.substr(nxt + 1, cur - nxt));
    cur = nxt;
  }

  reverse(ans.begin(), ans.end());
  for (string str : ans) {
    cout << str << "\n";
  }
}
