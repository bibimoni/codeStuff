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

string to_string(bigint n) {
  return n.to_string();
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    } 
    sort(a.begin(), a.end());
    int ans = (a[0] + a[n - 1]) / 2;
    int i = 1, j = n - 2;
    while (i < j) {
      (ans = ans + (a[i] + a[j]) / 2) /= 2;
      dbg(ans);
      i += 1;
      j -= 1;
    }
    cout << ans << '\n';
  }
}


