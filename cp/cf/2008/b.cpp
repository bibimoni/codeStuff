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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    vector<int> c0(n + 1, 0), c1(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      c0[i] = c0[i - 1] + (s[i] == '0');
      c1[i] = c1[i - 1] + (s[i] == '1');
    } 
    auto range = [&] (int l, int r, int t) -> int {
      if (t == 1) {
        return c1[r] - c1[l - 1];
      }
      return c0[r] - c0[l - 1];
    };
    if ((int) sqrt(n) * (int) sqrt(n) != (int) (sqrt(n) * sqrt(n))) {
      cout << "NO\n";
      continue;
    }
    int l = sqrt(n);
    int sz = n / l;
    bool ok = (range(1, sz, 1) == sz) && (range(n - sz + 1, n, 1) == sz);
    for (int i = sz + 1; i <= n - sz; i += sz) {
      if (s[i] == '1' && s[i + sz - 1] == '1' && range(i + 1, i + sz - 2, 0) == sz - 2) {
        continue;
      }
      ok = false;
      break;
    }
    cout << (ok ? "Yes\n" : "No\n");
  }
}


