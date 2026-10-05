/**
 * Author: distiled
 */
#include <bits/stdc++.h>
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
  int n, m;
  cin >> n >> m;
  vector<int> f(n);
  vector<int> cnt(m + 1);
  for (int i = 0; i < n; i++) {
    cin >> f[i];
    cnt[f[i]] += 1;
  }
  sort(f.begin(), f.end());
  bool ans1 = true;
  for (int i = 0; i + 1 < n; i++) {
    ans1 &= f[i] != f[i + 1];
  }

  bool ans2 = true;
  for (int i = 1; i <= m; i++) {
    ans2 &= cnt[i] > 0;
  }

  cout << (ans1 ? "Yes" : "No") << '\n';
  cout << (ans2 ? "Yes" : "No") << '\n';
}
