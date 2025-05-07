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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> b(m);
    vector<int> ll;
    for (int i = 0; i < m; i++) {
      cin >> b[i];
    }
    int j = 0;
    for (int i = 0; i < n; i++) {
      if (j < m && a[i] >= b[j]) {
        j += 1;
      }
    }
    if (j == m) {
      cout << "0\n";
      continue;
    }
    const int INF = (int) 1e18;
    int ans = INF;
    if (j == m - 1) {
      ans = b[m - 1];
    }
    vector<int> idx(n, -1);
    j = m - 1;
    for (int i = n - 1; i >= 0; i--) {
      if (j < m && b[j] <= a[i]) {
        idx[i] = j;
        j -= 1;
      }
    }
    for (int i = n - 2; i >= 0; i--) {
      if (idx[i] == -1) {
        idx[i] = idx[i + 1];
      }
    }
    j = 0;
    for (int i = 0; i < n; i++) {
      if (idx[i] != -1 && idx[i] <= j + 1) {
        dbg(i, idx[i], j);
        ans = min(ans, b[j]);
      }
      if (j < m && a[i] >= b[j]) {
        j += 1;
      }
    }
    cout << (ans == INF ? -1 : ans) << '\n';
  }
}
