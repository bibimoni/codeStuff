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
#define int int64_t 

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  int ans = 0;
  vector<int> a(2 * n);
  for (int i = 0; i < 2 * n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i + 2 < 2 * n; i++) {
    ans += a[i] == a[i + 2];
  }
  cout << ans << '\n';
}


