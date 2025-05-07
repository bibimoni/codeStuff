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
  int n, t;
  cin >> n >> t;
  int a[n + 1];
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int q;
  cin >> q;
  while(q--) {
    string s;
    int l, r;
    cin >> s >> l >> r;
    if(s == "get") {
      int ans = 0;
      for(int i = l; i <= r; i++) {
        ans += a[i];
      }
      cout << ans * t << '\n';
    }
    else {
      for(int i = l; i <= r; i++) {
        a[i] ^= 1;
      }
    }
  }
}

