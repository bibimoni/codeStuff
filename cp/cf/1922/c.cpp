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

const int INF = (int) 1e18;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n; cin >> n;
    int a[n + 2];
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    a[0] = -INF;
    vector<int> pref(n + 1, 0);
    for(int i = 2; i <= n; i++) {
      int cost;
      if(abs(a[i - 1] - a[i - 2]) > abs(a[i] - a[i - 1])) {
        cost = 1;
      }
      else {
        cost = abs(a[i] - a[i - 1]);
      }
      pref[i] = pref[i - 1] + cost;
    }
    a[n + 1] = INF;
    vector<int> suf(n + 2, 0);
    for(int i = n - 1; i >= 1; i--) {
      int cost;
      if(abs(a[i + 1] - a[i + 2]) > abs(a[i] - a[i + 1])) {
        cost = 1;
      }
      else {
        cost = abs(a[i] - a[i + 1]);
      }
      suf[i] = suf[i + 1] + cost;
    }
    int m; cin >> m;
    while(m--) {
      int x, y; cin >> x >> y;
      if(x < y) {
        cout << pref[y] - pref[x] << '\n';
      }
      else {
        cout << suf[y] - suf[x] << '\n';
      }
    }
  }
}


