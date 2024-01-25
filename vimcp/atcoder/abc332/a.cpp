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

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, s, k; cin >> n >> s >> k;
  int cost = 0;
  for(int i = 0; i < n; i++) {
    int p, q; cin >> p >> q;
    cost += p * q;
  }
  if(cost < s) cost += k;
  cout << cost << '\n';
}


