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
  vector<int> a(n + 1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ans = max(ans, a[i]);
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      ans = max(ans, a[i] | a[j]);
      for (int k = j - 1; k >= 1; k--) {
        ans = max(ans, a[i] | a[j] | a[k]); 
      }
    }
  }
  cout << ans << '\n';
}

