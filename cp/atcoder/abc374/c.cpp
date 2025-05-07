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
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = int(1e18);
  for (int mask = 0; mask < (int(1) << n); ++mask) {
    vector<int> gr(2);
    for (int j = 0; j < n; j++) {
      gr[(mask >> j & 1)] += a[j];
    }
    ans = min(max(gr[0], gr[1]), ans);
  }
  cout << ans << '\n';
}


