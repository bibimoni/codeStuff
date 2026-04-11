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
#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> b(n);
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      mp[b[i]].push_back(i);
    }

    vector<int> ans(n);
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    bool ok = true;
    for (auto &[k, v] : mp) {
      if (v.size() % k != 0) {
        ok = false;
        break;
      }
      int cnt = 0;
      for (int id : v) {
        ans[id] = p.back();
        cnt += 1;
        if (cnt == k) {
          cnt = 0;
          p.pop_back();
        }
      }
      if (cnt != 0) {
        ok = false;
        break;
      }
    }

    if (!ok) {
      cout << "-1\n";
    } else {
      for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
      }
    }
  }
}
