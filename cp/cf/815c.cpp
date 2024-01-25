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
  int n, b; 
  cin >> n >> b;
  int c[n + 1], d[n + 1], x[n + 1];
  for(int i = 1; i <= n; i++) {
    cin >> c[i] >> d[i];
    if(i >= 2) {
      cin >> x[i];
    }
  }
  vector<array<int, 3>> dp(n + 1, array<int, 3>({0, 0, 0}));
  for(int i = 1; i <= n; i++) {

  }
}

