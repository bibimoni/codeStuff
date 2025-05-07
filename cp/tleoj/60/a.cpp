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
  freopen("REMOVE.inp", "r", stdin);
  freopen("REMOVE.out", "w", stdout);
  int v, h;
  cin >> v >> h;
  cout << 1 + (v % h != 0);
}

