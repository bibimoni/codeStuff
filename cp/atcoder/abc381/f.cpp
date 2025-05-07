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
  vector<int> a(n + 1);
  vector<int> s;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s.push_back(a[i]);
  }
  sort(s.begin(), s.end());
  s.erase(unique(s.begin(), s.end()), s.end());
  for (int i = 1; i <= n; i++) {
    a[i] = lower_bound(s.begin(), s.end(), a[i]) - s.begin();
  }
  int m = s.size();
 
  vector nxt (n + 2, vector (m, n + 1));
  for (int ss = 0; ss < m; ss++) {
    int cur = n + 1;
    for (int i = n; i >= 0; i--) {
      nxt[i][ss] = cur;
      if (a[i] == ss) {
        cur = i;
      }
    }
  }

  auto find = [&] (int from, int ss) -> int {
    if (from == n + 1) {
      return n + 1;
    }
    from = nxt[from][ss];
    if (from == n + 1) {
      return n + 1;
    }
    return nxt[from][ss];
  };

  vector dp(int(1) << m, n + 1);
  dp[0] = 0;
  for (int mask = 0; mask < (int(1) << m); mask++) {
    for (int j = 0; j < m; j++) {
      if ((mask >> j) & 1) {
        continue;
      }
      if (dp[mask] == n + 2 || find(dp[mask], j) == n + 1) {
        continue;
      }
      dp[mask | (int(1) << j)] = min(dp[mask | (int(1) << j)], find(dp[mask], j));
    }
  }
  int ans = 0;
  for (int mask = 0; mask < (int(1) << m); mask++) {
    if (dp[mask] <= n) {
      ans = max(ans, (int)__builtin_popcountll(mask));
    }
  }
  cout << ans * 2 << '\n';
} 


