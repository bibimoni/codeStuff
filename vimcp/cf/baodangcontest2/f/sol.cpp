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
  int ans = 0, even = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> bits(32, 0);
  for(int i = 0; i < n; i++) {
    if(!a[i]) {
      ans += even;
    }
    if(a[i] % 2 == 0) even++;
    if(a[i]) {
      int t = __builtin_clzll(a[i]);
      bits[t]++;
    }
  }
  for(int i = 0; i < 31; i++) {
    int m = bits[i];
    ans += m * (m + 1) / 2; 
  }
  cout << ans;
}

