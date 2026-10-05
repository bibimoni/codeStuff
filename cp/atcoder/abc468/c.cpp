/**
 * Author: distiled
 */
#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
// #define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  vector<int> q(n);
  for (int i = 0; i < n; i++) {
    cin >> q[i];
  }

  vector<int> ini(n);
  int ans = 0;
  iota(ini.begin(), ini.end(), 1);
  do {
    auto cmp = [&](vector<int> &x, vector<int> &y) -> bool {
      for (int i = 0; i < int(x.size()); i++) {
        if (x[i] > y[i]) {
          return true;
        } else if(x[i] < y[i]) {
          return false;
        }
      }
      return false;
    };
    if (cmp(ini, p) and cmp(q, ini)) {
      ans += 1;
    } 
  } while (next_permutation(ini.begin(), ini.end()));

  cout << ans; 
}
