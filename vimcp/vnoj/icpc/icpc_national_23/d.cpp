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

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n; cin >> n;
    int a[n], ans = 0, prev = -1; 
    vector<int> idx(n, -1);
    for(int i = 0; i < n; i++) {
      cin >> a[i]; a[i]--;
      prev = max(prev, idx[a[i]]);
      ans += (i - prev);
      idx[a[i]] = i;
    }
    cout << ans << '\n';
  }
}

