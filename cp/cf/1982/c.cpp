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
#define int long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int ans = 0, j = 1, curr = 0;
    for (int i = 1; i <= n; i++) {
      curr += a[i];
      while(j <= i && curr > r) {
        curr -= a[j++];
      }
      if(l <= curr && curr <= r) {
        ans++;
        j = i + 1;
        curr = 0;
      }
    }
    cout << ans << '\n';
  }
}


