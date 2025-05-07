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
    vector<vector<string>> b(m);
    int ans = 0;
    for (int i = 0; i < m; i++) {      
      int cnt = 0;
      b[i].resize(n);
      for (int j = 0; j < n; j++) {
        cin >> b[i][j];
        if (b[i][j] == a[j]) {
          cnt += 1;
        }
      }
      ans = max(ans, cnt);
    }

    bool ok = true;
    for (int i = 0; i < n; i++) {
      bool fn = false;
      for (int j = 0; j < m; j++) {
        fn |= b[j][i] == a[i];
      }
      ok &= fn;
    }

    if (!ok) {
      cout << "-1\n";
    } else {
      cout << n + 2 * (n - ans) << '\n';
    }   
  }
}


