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
#define pb             push_back
#define all(x)         x.begin(), x.end()
#define sz(x)          (int) x.size()
#define endl           '\n'
#define MULTI          int t;cin>>t;while(t--)
inline int nxt() { int n; cin >> n; return n; }

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m, k; cin >> n >> m >> k;
  int emenies = 0; 
  vector<string> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    for(int j = m - 1; j >= 0; j--) {
      if(a[i][j] == 'x') emenies++;
    }
  }
  auto good = [&] (int v) {
    int rem = k, toBeKilled = emenies;
    for(int i = 0; i < n; i++) {
      int j = 0;
      while(j < m) {
        for(; j < m; j++) if(a[i][j] == 'x') break;
        if(j >= m) break;
        rem--; int t = j;
        for(; t < min(j + 2 * v + 1, m); t++) {
          if(a[i][t] == 'x') toBeKilled--;
          if(a[i][t] == '#') break;
        }
        j = t;
      }
    }
    return rem >= 0 && toBeKilled == 0;
  };
  int ans = -1, l = 0, r = (int) 1e9;
  while(l <= r) {
    int mid = (l + r) >> 1;
    if(good(mid)) {
      r = mid - 1;
      ans = mid; 
    }
    else {
      l = mid + 1;
    }
  }
  cout << ans;
}



