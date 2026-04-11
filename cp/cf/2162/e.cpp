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
    int n, k;
    cin >> n >> k;
    vector<int> a;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (a.size() && a.back() == x) {
        continue;
      }
      a.push_back(x);
    }

    vector<int> rem;
    set<int> st{a.begin(), a.end()};
    for (int x = 1; x <= n; x++) {
      if (st.find(x) == st.end()) {
        rem.push_back(x);
      }
    }
    vector<int> ans;
    n = a.size();
    if (rem.size() < 3) {
      for (int i = 0; i < int(rem.size()); i++) {
        ans.push_back(rem[i]);
        a.push_back(rem[i]);
      }
      for (int i = 0; i < 3; i++) {
        if (rem.size() >= 3) {
          break;
        }
        for (int x = 1; x <= n; x++) {
          bool ok = true;
          for (int j = a.size() - 1; j >= (int)a.size() - 2; j--) {
            ok &= x != a[j];
          }
          dbg(a, x, ok);
          if (ok) {
            rem.push_back(x);
            a.push_back(x);
            ans.push_back(x);
            break;
          }
        }
      }
    }
    dbg(rem);

    int j = 0;
    while ((int)ans.size() < k) {
      ans.push_back(rem[j]);
      j = (j + 1) % rem.size();
    }

    while ((int)ans.size() > k) {
      ans.pop_back();
    }

    for (int x : ans) {
      cout << x << ' ';
    }
    cout << '\n';
  }
}
