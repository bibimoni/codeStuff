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
    int n, q;
    cin >> n >> q;
    string a, b;
    cin >> a >> b;
    a = " " + a;
    vector<vector<int>> cntA(n + 1, vector<int>(26, 0));
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < 26; j++) {
        cntA[i][j] = cntA[i - 1][j] + int((a[i] - 'a') == j);
      }
    }
    b = " " + b;
    vector<vector<int>> cntB(n + 1, vector<int>(26, 0));
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < 26; j++) {
        cntB[i][j] = cntB[i - 1][j] + int((b[i] - 'a') == j);
      }
    }
    while (q--) {
      int l, r;
      cin >> l >> r;
      int ans = 0;
      for (int j = 0; j < 26; j++) {
        int ca = cntA[r][j] - cntA[l - 1][j];
        int cb = cntB[r][j] - cntB[l - 1][j];
        ans += abs(ca - cb);
      }
      cout << ans / 2 << '\n';
    }
  }
}


