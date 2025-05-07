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
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  vector<vector<int>> s(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s[a[i] % m].push_back(i);
  }
  auto need = [&] (int x, int y) {
    if (x <= y) {
      return y - x;
    }
    return m - x + y;
  };
  deque<int> cur;
  int ans = 0;
  for (int k = 0; k < 2; k++) {
    for (int i = 0; i < m; i++) {
      while (s[i].size() > n / m) {
        cur.push_back(s[i].back());
        s[i].pop_back();
      }
      while (cur.size() && s[i].size() < n / m) {
        int idx = cur.back();
        cur.pop_back();
        s[i].push_back(idx);
        int v = need(a[idx] % m, i);
        a[idx] += v;
        ans += v;
      }
    }
  }
  cout << ans << '\n';
  for (int i = 0; i < n; i++) {
    cout << a[i] << " \n"[i == n - 1];
  }
}
