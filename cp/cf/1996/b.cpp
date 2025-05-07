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
    int n, k;
    cin >> n >>  k;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < n; j++) {
        a[i][j] = s[j] - '0';
      }
    }
    vector<vector<int>> ans(n / k, vector<int>(n / k));
    for (int i = 0; i < n; i += k) {
      for (int j = 0; j < n; j += k) {
        ans[i / k][j / k] = a[i][j];
      }
    }
    for (int i = 0; i < n; i += k) {
      for (int j = 0; j < n; j += k) {
        cout << ans[i / k][j / k];
      }
      cout << '\n';
    }
  }
}


