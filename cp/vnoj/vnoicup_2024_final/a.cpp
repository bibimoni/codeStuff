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

// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 


signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<pair<int, int>> ans;
    int diff = int(2e9);
    for (int cur = 1; cur <= k; cur++) {
      vector<int> mark(n, 0);
      vector<pair<int, int>> tmp;
      for (int i = 0; i < n; i++) {
        if (mark[i] || i + cur >= n || mark[i + cur]) {
          continue;
        }
        tmp.emplace_back(i, i + cur);
        mark[i + cur] = 1;
        mark[i] = 1;
      }
      vector<int> rem;
      for (int i = 0; i < n; i++) {
        if (mark[i]) {
          continue;
        }
        rem.push_back(i);
      }
      for (int i = 0; i < int(rem.size()) - i; i++) {
        tmp.emplace_back(rem[i], rem[i + int(rem.size() / 2)]);
      }
      int mn = int(2e9), mx = 0;
      for (auto [u, v] : tmp) {
        mn = min(mn, a[u] + a[v]);
        mx = max(mx, a[u] + a[v]);
      }
      if (diff > mx - mn) {
        diff = mx - mn;
        swap(ans, tmp);
      }
    }
    cout << diff << '\n';
    for (auto [u, v] : ans) {
      cout << u + 1 << ' ' << v + 1 << '\n';
    }
  }
}

