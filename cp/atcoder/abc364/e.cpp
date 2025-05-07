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

int backtrack(int k, int sw, int ss, set<int> &picked, int x, int y, int n, vector<int> &a, vector<int> &b, vector<map<pair<int, int>, int>> &memo) {
  // dbg(ss, sw, picked);
  if (k == n) {
    return k;
  }
  if (sw > x || ss > y) {
    return k;
  }
  if (memo[k].count({sw, ss})) {
    return memo[k][{sw, ss}];
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (picked.find(i) == picked.end()) {
      picked.insert(i);
      ans = max(ans, backtrack(k + 1, sw + a[i], ss + b[i], picked, x, y, n, a, b, memo));
      picked.erase(i);
    }
  }
  return (memo[k][{sw, ss}] = ans);
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> a(n + 2, 0);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> b(n + 2, 0);
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  set<int> tmp;
  vector<map<pair<int, int>, int>> memotmp(n + 1);
  cout << backtrack(0, 0, 0, tmp, x, y, n, a, b, memotmp);
  
}


