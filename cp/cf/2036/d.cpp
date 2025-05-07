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
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < min(n, m) - i; i++) {
      string cur = "";
      int bxl = i, bxr = n - i - 1;
      int byl = i, byr = m - i - 1;
      for (int j = byl; j <= byr; j++) {
        cur += a[bxl][j];
      }
      for (int j = bxl + 1; j <= bxr; j++) {
        cur += a[j][byr];
      }
      for (int j = byr - 1; j >= byl; j--) {
        cur += a[bxr][j];
      }
      for (int j = bxr - 1; j > bxl; j--) {
        cur += a[j][byl];
      }
      for (int j = 0; j < cur.size(); j++) {
        ans += cur[j] == '1' && cur[(j + 1) % cur.size()] == '5'
          && cur[(j + 2) % cur.size()] == '4' && cur[(j + 3) % cur.size()] == '3';
      }
    }
    cout << ans << '\n';
  }
}


