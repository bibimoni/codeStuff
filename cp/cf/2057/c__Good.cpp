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
    int l, r;
    cin >> l >> r;
    auto calc = [&] (int v1, int v2, int v3) -> int {
      return (v1 ^ v2) + (v2 ^ v3) + (v1 ^ v3);
    };
    int cur = 0;
    vector<int> p;
    for (int t1 = l; t1 <= r; t1++) {
      for (int t2 = t1 + 1; t2 <= r; t2++) {
        for (int t3 = t2 + 1; t3 <= r; t3++) {
          if (cur < calc(t1, t2, t3)) {
            cur = calc(t1, t2, t3);
            p = vector<int>{t1, t2, t3};
          }
        }
      }
    }
    dbg(cur, p);
  }
}

