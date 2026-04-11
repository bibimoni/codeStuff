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
  int n;
  cin >> n;
  vector<pair<int, int>> a;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a.push_back({x, i + 1});
  }

  sort(a.begin(), a.end());
  for (int i = 0; i < 3; i++) {
    cout << a[i].second << ' ';
  }
}
