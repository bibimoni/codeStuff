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
  int n, k;
  cin >> n >> k;
  vector<int> p(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  vector<vector<int>> cycle(n + 1);
  map<int, pair<int, int>> idx;
  vector<int> was(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    if (!was[i]) {
      int v = i;
      int cnt = 0;
      while (true) {
        cycle[i].push_back(v);
        idx[v] = {i, cnt};
        cnt += 1;
        was[v] = 1;
        v = p[v];
        if (v == i) {
          break;
        }
      }
    }
  }
  auto pow_mod = [&] (int a, int b, int m) -> int {
    int ret = 1, y = a;
    while (b) {
      if (b & 1) {
        (ret *= y) %= m;
      }
      (y *= y) %= m;
      b >>= 1;
    }
    return ret;
  };

  for (int i = 1; i <= n; i++) {
    auto [u, v] = idx[i];
    int go_to = pow_mod(int(2), k, cycle[u].size());
    cout << cycle[u][(v % cycle[u].size() + go_to) % cycle[u].size()] << " \n"[i == n];
  }
}


