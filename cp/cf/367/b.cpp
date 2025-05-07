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
  int n, m, p;
  cin >> n >> m >> p;
  vector<int> s;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> b(m + 1);
  map<int, int> base;
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    base[b[i]] += 1;
  }
  vector<int> ans;
  for (int start = 1; start <= p; start++) {
    int cnt = 0;
    map<int, deque<int>> f;
    int sz = 0;
    for (int i = start; i <= n; i += p) {
      if (cnt >= m) {
        int val = a[i - m * p], idx = i - m * p;
        if (f[val].size() > 0 && f[val].front() == i - m * p) {
          sz -= 1;
          f[val].pop_front();;
        }
      }
      if (base[a[i]] > 0) {
        if (f[a[i]].size() > 0 && f[a[i]].size() == base[a[i]]) {
          int val = a[i];
          sz -= 1;
          f[val].pop_front();
        }
        f[a[i]].push_back(i);
        sz += 1;
      }
      if (sz == m) {
        ans.push_back(i - (m - 1) * p);
      }
      cnt += 1;
    }
  } 
  sort(ans.begin(), ans.end());
  cout << ans.size() << '\n';
  for (int i = 0; i < int(ans.size()); i++) {
    cout << ans[i] << " \n"[i == int(ans.size()) - 1];
  }
}

