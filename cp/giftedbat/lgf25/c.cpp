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
  int n;
  cin >> n;
  vector<int> a(n);
  int mx = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mx = max(a[i], mx);
  }
  if (mx <= (int)5e5) {
    const int BOUND = (int)1000;
    for (int val : a) {
      vector<int> divs;
      for (int i = 1; i * i <= val; i++) {
        if (val % i == 0) {
          divs.push_back(i);
        }
      }
      bool ok = false;
      for (int div : divs) {
        for (int x = 0; x <= BOUND; x++) {
          int y = div ^ x;
          int dd = val / div;
          int rem = dd - x - y;
          int half = rem / 2;
          int nx = half | x;
          int ny = half | y;
          if (nx + ny == dd) {
            ok = true;
            break;
          }
          if (val / div == (x ^ (div - x))) {
            ok = true;
            break;
          }
        }
      }

      if (ok) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  } else {
    const int BOUND = 32000;
    vector<pair<int, int>> divs;
    for (int i = 0; i < n; i++) {
      int val = a[i];
      for (int j = 1; j * j <= val; j++) {
        if (val % j == 0) {
          divs.push_back({j, i});
          // if (i * i != val) {
          //   divs.push_back(val / i);
          // }
        }
      }
    }
    dbg(divs);
    vector<int> ans(n, 0);
    for (int x = 0; x <= BOUND; x++) {
      for (auto [div, i] : divs) {
        if (ans[i]) {
          continue;
        }
        int val = a[i];
        int s1 = div;
        int s2 = val / div;
        int y1 = s1 ^ x;
        int y2 = s2 - x;
        if (y1 == y2) {
          ans[i] = 1;
        }
      }
    }

    for (int i = 0; i < n; i++) {
      cout << (ans[i] ? "YES\n" : "NO\n");
    }
  }
}
