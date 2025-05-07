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
#define int long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<vector<int>> idx(n + 1);
    for(int i = 0; i < n; i++) {
      a[i] = n - a[i];
      idx[a[i]].push_back(i);
    }
    set<int> s;
    vector<int> seg(n + 1);
    seg[n] += n;
    s.insert({-1, n});
    auto add = [&] (int h, int id) {
      int p1 = *s.lower_bound(id);
      int p2 = *prev(s.lower_bound(id));
      seg[p1 - p2 - 1] -= h;
      seg[id - p2 - 1] += h;
      seg[p1 - id - 1] += h;
      s.insert(id);
    };
    for(int i = n; i >= 1; i--) {
      for(int j : idx[i]) {
        add(i, j);
      }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
      cout <<  seg[i] << " \n"[i == n];
    }
    cout << ans << '\n';
  }
}

