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
  int n; cin >> n;
  int ans = 0, a[n];
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  bool has = false;
  for(int i = 1; i <= n; i++) {
    has = false;
    for(int t : a) {
      if(t < i) {
        ans += (int) has;
        has = false;
      }
      else has = true;
    }
    ans += (int) has;
  }
  cout << ans;
}

