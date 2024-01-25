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

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n; cin >> n;
  int a[n];
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int g = a[0];
  for(int i = 1; i < n; i++) {
    g = __gcd(a[i], g);
  }
  int ans = 0;
  for(int i = 0; i < n; i++) {
    ans += (a[i] / g) - 1;
  }
  cout << ans << '\n';
}

