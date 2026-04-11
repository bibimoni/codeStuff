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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> mark(n + 1);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      mark[a[i]] = 1;
    }

    sort(a.begin(), a.end());
    int cur_mex = 0;
    vector<int> mexs(n);
    for (int i = 0; i < n; i++) {
      if (a[i] == cur_mex) {
        cur_mex += 1;
      }
      mexs[i] = cur_mex;
    }
    dbg(mexs);
  }
}
