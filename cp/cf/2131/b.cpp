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
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        ans.push_back(-1);
      } else {
        ans.push_back(3);
      }
    }
    if (n % 2 == 0) {
      ans.pop_back();
      ans.push_back(2);
    }
    for (int x : ans) {
      cout << x << ' ';
    }
    cout << '\n';
  }
}
