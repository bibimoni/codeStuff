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
  int l, r, a, k;
  cin >> l >> r >> a >> k;
  int u = k / __gcd(a, k);
  l = (l + u - 1) / u;
  r /= u;
  cout << r - l + 1;
}

