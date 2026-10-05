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
// #define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, d;
  cin >> n >> d;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  sort(p.begin(), p.end(), [&] (int i, int j) {
      return a[i] < a[j];
  });

  vector<int> ans;
  for (int i = 0; i < n; i++) {
    int id = p[i];
    bool ok = true;
    if (i > 0)
      ok &= a[id] - a[p[i - 1]] >= d;
    if (i < n - 1)
      ok &= a[p[i + 1]] - a[id] >= d;
    if (ok) {
      ans.push_back(id + 1);
    }
  }

  sort(ans.begin(), ans.end());
  cout << ans.size() << '\n';
  for (int i : ans) {
    cout << i << " "; 
  }
}
