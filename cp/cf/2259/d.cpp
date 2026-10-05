/**
 * Author: distiled
 */
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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      mp[a[i]].push_back(i);
    }

    array<int, 3> s{0, 0, 0};
    array<bool, 3> ok{true, true, true};
    vector<char> ans(n);
    for (auto &[val, v] : mp) {
      if (v.size() == 1 && ok[0] && ok[1]) {
        ans[v[0]] = 'C';
        if (ok[2] && val == s[2]) {
          s[2] += 1;
        }
        continue;
      }
      if (ok[0] && val == s[0]) {
        s[0] += 1;
      } else {
        ok[0] = false;
      }
      if (v.size() > 1 && ok[1] && val == s[1]) {
        s[1] += 1;
      } else {
        ok[1] = false;
      }

      for (int i = 1; i < int(v.size()); i++) {
        ans[v[i]] = 'A'; 
      }
      ans[v[0]] = 'B';
    }

    if (s[0] + s[1] + s[2] < 2 * (*max_element(s.begin(), s.end()))) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      for (int i = 0; i < n; i++) {
        cout << ans[i];
      }
      cout << '\n';
    }
  }
}
