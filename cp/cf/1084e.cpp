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
  int n, k; cin >> n >> k;
  string s, t; cin >> s >> t;
  int ans = 0, curr = 1;  
  for(int i = 0; i < n; i++) {
    curr *= 2;
    if(s[i] == 'b') curr--;
    if(t[i] == 'a') curr--;
    if(curr <= 0) {
      curr = 1;
    }
    if(curr > k) curr = k;
    ans += curr;

  }  
  cout << ans;
}

