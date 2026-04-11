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
    string s;
    cin >> s;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        p[i] = i + 1;
      }
    }

    vector<int> cur;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        cur.push_back(i);
      }
      if (s[i] == '1') {
        if (cur.size() == 1) {
          ok = false;
          break;
        }
        for (int j = 0; j < int(cur.size()); j++) {
          p[cur[j]] = cur[(j + 1) % int(cur.size())] + 1;
        }
        cur.clear();
      }
    }

    if (cur.size() == 1) {
      ok = false;
    }
    for (int j = 0; j < int(cur.size()); j++) {
      p[cur[j]] = cur[(j + 1) % int(cur.size())] + 1;
    }

    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        ok &= p[i] == i + 1;
      } else {
        ok &= p[i] != i + 1;
      }
    }
    if (!ok) {
      cout << "No\n";
      continue;
    }
    cout << "Yes\n";
    for (int i = 0; i < n; i++) {
      cout << p[i] << " \n"[i == n - 1];
    }
  }
}
