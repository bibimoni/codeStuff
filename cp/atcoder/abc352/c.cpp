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
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  int tot = 0, ans = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
    tot += a[i].first;
  }
  for(int i = 0; i < n; i++) {
    ans = max(ans, tot - a[i].first + a[i].second);
  }
  cout << ans;
}


