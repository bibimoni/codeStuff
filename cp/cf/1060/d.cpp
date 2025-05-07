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
  vector<int> l(n + 1), r(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
  }
  int ans = n;
  sort(l.begin() + 1, l.end());
  sort(r.begin() + 1, r.end());
  for (int i = 1; i <= n; i++) {
    ans += max(l[i], r[i]);
  }  
  cout << ans << '\n';
}

