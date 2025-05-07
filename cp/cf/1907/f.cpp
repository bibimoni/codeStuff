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

const int INF = (int) 2e9;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    if(n == 1 || is_sorted(a, a + n)) {
      cout << "0\n";
      continue;
    }
    if(is_sorted(a, a + n, greater<int>())) {
      cout << "1\n";
      continue;
    }
    int ans = INF;
    int idxU = -1, idxD = -1;
    bool ok1 = true, ok2 = true;
    for(int i = 0; i < n - 1; i++) {
      if(a[i] > a[i + 1] && idxU == -1 && ok1) idxU = i + 1;
      else if(a[i] > a[i + 1] && idxU != -1) idxU = -1, ok1 = false;
      if(a[i] < a[i + 1] && idxD == -1 && ok2) idxD = i + 1;
      else if(a[i] < a[i + 1] && idxD != -1) idxD = -1, ok2 = false;
    }
    if(idxU != -1 && a[n] <= a[0] && ok1) ans = min(ans, n - idxU);
    if(idxD != -1 && a[n] >= a[0] && ok2) ans = min(ans, n - idxD + 1);
    dbg(ok1, ok2)
    if(ans == INF) cout << -1 << '\n';
    else cout << ans << '\n';
  }
}


