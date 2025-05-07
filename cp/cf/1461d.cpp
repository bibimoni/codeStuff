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
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> pre(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      pre[i] = pre[i - 1] + a[i];
    }
    auto range = [&] (int l, int r) -> int {
      return pre[r] - pre[l - 1];
    };
    set<int> can;
    auto go = [&] (auto &&self, int u, int v) -> void {
      if (u > v) {
        return;
      }
      can.insert(range(u, v));
      if (u == v) {
        return;
      }
      int l = u, r = v, ret = -1, pivot = (a[u] + a[v]) >> 1;
      while (l <= r) {
        int m = (l + r) >> 1;
        if (a[m] > pivot) {
          r = m - 1;
        } else {
          ret = m;
          l = m + 1;
        }
      }
      if (ret != -1 && ret != v) {
        self(self, u, ret);
        self(self, ret + 1, v);
      } 
    };
    go(go, 1, n);
    while (q--) {
      int si;
      cin >> si;
      cout << (can.find(si) != can.end() ? "Yes\n" : "No\n");
    }
  }
}

