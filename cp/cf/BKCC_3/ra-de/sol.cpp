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
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  const int mx = 30;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<vector<int>> mark(mx + 1);
  vector<int> sum(mx + 1);
  for (int i = 0; i < n; i++) {
    mark[a[i]].push_back(i);
    sum[a[i]] += a[i];
  }

  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }

  b.push_back(1);
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());
  reverse(b.begin(), b.end());
  m = int(b.size());

  vector<int> h(mx + 1), g(mx + 1);
  for (int x : b) {
    for (int j = x; j <= mx; j += x) {
      g[x] += sum[j];
      h[x] += int(mark[j].size());
    }
  }
  dbg(g, h);

  vector<int> s(mx + 1);
  for (int x : b) {
    s[x] = (g[x] / x) * (h[x] - 1);
    for (int j = x * 2; j <= mx; j += x) {
      s[x] -= (s[j] * (j / x));
    }
    dbg(s[x], x);
  }
  dbg(s);

  int ans = accumulate(s.begin(), s.end(), int(0)) / 2;
  cout << ans << '\n';
}
