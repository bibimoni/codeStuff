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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> b(n / 2 + 1);
    vector<int> ans(n + 1, 0);
    vector<int> used(n + 1, 0);
    bool ok = true;
    for (int i = 1; i * 2 <= n; i++) {
      cin >> b[i];
      ans[i * 2] = b[i];
      if (used[b[i]]) {
        ok = false;
      }
      used[b[i]] = 1;
    }
    if (!ok) {
      cout << "-1\n";
      continue;
    }
    vector<int> prev(n + 1, 0);
    for (int i = 2; i <= n; i++) {
      if (used[i - 1] != 0) {
        prev[i] = prev[i - 1];
      } else {
        prev[i] = i - 1;
      }
    }
    vector<int> occupied(n + 2, 0);
    vector<pair<int, int>> st;
    for (int i = n / 2; i >= 1; i--) {
      int t = prev[b[i]];
      int bf = t;
      while (t > 0 && occupied[t] != 0) {
        prev[bf] = prev[t];
        t = prev[t];
      }
      if (t == 0) {
        ok = false;
        break;
      }
      occupied[t] = 1;
      st.push_back({t, 2 * i - 1});
    }
    if (!ok) {
      cout << "-1\n";
      continue;
    }
    sort(st.begin(), st.end());
    for (auto [v, i] : st) {
      ans[i] = v;
    }
    auto checkPermutation = [&] (vector<int> p) -> bool {
      sort(p.begin(), p.end());
      int curr = 1;
      for (int i = 1; i <= n; i++) {
        if (p[i] != curr) {
          return false;
        }
        curr += 1;
      }
      return true;
    };
    if (!checkPermutation(ans)) {
      cout << "-1\n";
      continue;
    }
    for (int i = 1; i <= n; i++) {
      cout << ans[i] << " \n"[i == n];
    }
  }
}

