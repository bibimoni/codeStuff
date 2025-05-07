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
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  int q;
  cin >> q;
  while (q--) {
    int t, d;
    cin >> t >> d;
    t -= 1;
    auto [q, r] = a[t];
    int x = d;
    d %= q;
    if (d > r) {
      cout << x + q - d + r << '\n';
    } else {
      cout << x + r - d << '\n';  
    }
  }
}


