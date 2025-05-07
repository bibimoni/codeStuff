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

const int L = 60;
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, q; cin >> n >> q;
  vector<int> a(n + 1), b(n + 1);
  for(int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  while(q--) {
    int k; cin >> k;
    a = b;
    int ans = 0;
    for(int j = L; j >= 0; j--) {
      int op = 0;
      for(int i = 1; i <= n; i++) {
        if(a[i] & (1ll << j)) continue;
        int change = a[i] & ((1ll << j) - 1);
        op += (1ll << j) - change;
        if(op > k) break;
      }
      if(op <= k) {
        ans += (1ll << j);
        k -= op;
        for(int i = 1; i <= n; i++) {
          if(a[i] & (1ll << j)) continue;
          int change = a[i] & ((1ll << j) - 1);
          a[i] += (1ll << j) - change;
        }
      }
    }
    int tmp = a[1];
    for(int i = 2; i <= n; i++) tmp &= a[i];
    cout << max(ans, tmp) << '\n';
  }
}


 