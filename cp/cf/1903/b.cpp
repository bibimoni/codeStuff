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

#define int            long long
#define all(x)         x.begin(), x.end()

const int INF = (int) 1e18, L = 5;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n; cin >> n;
    int m[n][n];
    int idx = -1, minE = INF;
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
      int curr = (1 << 30) - 1;
      for(int j = 0; j < n; j++) {
        cin >> m[i][j];
        if(i != j) {
          curr &= m[i][j];
        }
      }
      ans[i] = curr;
    }
    bool ok = true;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(i == j) continue;
        if((ans[i] | ans[j]) != m[i][j]) {
          ok = false;
          break;
        }
      }
    }
    dbg(ans);
    if(!ok) {
      cout << "NO\n";
      continue;
    }
    else {
      cout << "YES\n";
      for(int i : ans) cout << i << ' ';
        cout << '\n';
    }
  }
}


