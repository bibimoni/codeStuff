/**
 * Author: distiled
 */
#include <algorithm>
#include <bits/stdc++.h>
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
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
      cin >> t[i];
    }

    auto conv = [&](int x) -> int {
      int v = x % k;
      return k - v > v ? v : k - v;
    };
    map<int, int> mpt;
    map<int, int> mps;
    for (int i = 0; i < n; i++) {
      mpt[conv(t[i])] += 1;
      mps[conv(s[i])] += 1;
    }

    cout << (mps == mpt ? "YES\n" : "NO\n");
  }
}
