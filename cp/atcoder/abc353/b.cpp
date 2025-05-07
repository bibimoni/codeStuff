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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int seats = k, ans = 1;
  for(int i = 0; i < n; i++) {
    if(seats - a[i] >= 0) {
      seats -= a[i];
    }
    else {
      ans++;
      seats = k - a[i];
    }
  }
  cout << ans << '\n';
}


