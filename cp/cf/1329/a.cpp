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
  vector<int> l(m);
  for (int i = 0; i < m; i++) {
    cin >> l[i];
  }
  if (accumulate(l.begin(), l.end(), 0ll) < n) {
    cout << "-1\n";
    return 0;
  }
  bool ok = true;
  for (int i = 0; i < m; i++) {
    ok &= (i + l[i] <= n);
  }
  if (!ok) {
    cout << "-1\n";
    return 0;
  }
  vector<int> ans;
  int curr = 0;
  for (int i = m - 1; i >= 0; i--) {
    curr += l[i];
    ans.push_back(max(i + 1, n - curr + 1));
  }
  reverse(ans.begin(), ans.end());
  for (int i : ans) {
    cout << i << ' ';
  }
}

