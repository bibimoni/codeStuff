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
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> b(m + 1);
    set<int> st;
    for (int i = 1; i <= m; i++) {
      cin >> b[i];
    }
    sort(b.begin() + 1, b.end());
    while (q--) {
      int x;
      cin >> x;
      int l = 1, r = m, id = -1;
      while (l <= r) {
        int mid = (l + r) >> 1;
        if (b[mid] <= x) {
          id = mid;
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      }
      int nxt = -1, pre = -1;
      if (id == -1) {
        nxt = b[1];
      } else {
        pre = b[id];
        if (id < m) {
          nxt = b[id + 1];
        }
      }
      if (nxt == -1) {
        cout << n - pre << '\n';
      } else if (pre == -1) {
        cout << nxt - 1 << '\n';
      } else {
        int mid = (nxt + pre) / 2;
        cout << min(mid - pre, nxt - mid) << '\n';
      }
    }
  }
}


