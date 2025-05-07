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
    vector<int> a(n + 1);
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      pos[a[i]] = i;
    }
    set<int> cur;
    for (int i = 1; i <= n; i++) {
      if (pos[i]) {
        cur.insert(i);
      }
    }
    if (cur.size() == n) {
      cout << "2\n";
      continue;
    }
    vector<int> mark(n + 1, 0);
    int ans;
    for (int step = 0; step < n; step++) {
      vector<int> n_cur;
      int prev_sz = cur.size();
      bool is_del;
      while (cur.size()) {
        int u = cur.back();
        cur.pop_back();
        if (!mark[a[u]]) {
          n_cur.push_back(a[u]);
          mark[a[u]] = 1;
        }
      }
      if (prev_sz == n_cur.size()) {
        ans = 3 + step;
        break;
      }
      for (int cc : n_cur) {
        mark[cc] = 0;
      }
      swap(n_cur, cur);
    }
    cout << ans << '\n';
  }
}


