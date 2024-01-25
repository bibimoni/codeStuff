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
  int ans = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int i = 1; i < n; i++) {
    for(int j = i - 1; j >= 0; j--) {
      if((a[j] ^ a[i]) < (a[j] ^ (~a[i]))) ans++;
    }
  }
  cout << ans;
}

