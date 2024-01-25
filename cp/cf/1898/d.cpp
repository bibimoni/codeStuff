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

const int INF = (int) 1e18;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n; cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    int ans = 0, idxm, idxM, m = INF, M = 0ll;
    for(int i = 0; i < n; i++) {
      ans += abs(a[i] - b[i]);
      M = max(M, min(a[i], b[i]));
      m = min(m, max(a[i], b[i]));
    }
    cout << max(ans + 2 * (M - m), ans) << '\n';
  } 
}


