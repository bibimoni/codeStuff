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

const int N = (int) 1e6 + 5;
int f[N] = {};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  freopen("CAU2.INP", "r", stdin);
  freopen("CAU2.OUT", "w", stdout);
  int n; 
  cin >> n;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    f[x]++;
  }
  int ans = 0;
  for(auto i : f) {
    ans = max(ans, i);
  }
  cout << ans;
}


