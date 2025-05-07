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

const int N = (int) 2e5 + 5, INF = (int) 1e18;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    int ans = 0;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    vector<pair<int, int>> c(n);
    for(int i = 0; i < n; i++) {
      c[i] = {a[i] + b[i], i};
    }
    sort(c.begin(), c.end(), [&] (pair<int, int> m1, pair<int, int> m2) {return m1.first > m2.first;});
    for(int i = 0; i < n; i++) {
      int id = c[i].second;
      if(i & 1) {
        b[id]--; a[id] = 0;
      }
      else {
        a[id]--; b[id] = 0;
      }
    }
    for(int i = 0; i < n; i++) ans += a[i] - b[i];
    cout << ans << '\n';
  }
}


