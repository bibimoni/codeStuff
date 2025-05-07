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
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> b(n);
    map<int, int> cnt, same;
    for(int i = 0; i < n; i++) {
      cin >> b[i];
      if(a[i] == b[i]) {
        same[b[i]]++;
      }
      cnt[b[i]]++;
    }
    int m;
    cin >> m;
    vector<int> d(m);
    for(int i = 0; i < m; i++) {
      cin >> d[i];
    }
    bool ok = false;
    for(int i = m - 1; i >= 0; i--) {
      if(cnt.count(d[i])) {
        cnt[d[i]] -= (cnt[d[i]] == 0 ? 0 : 1);
        ok = true;
      }
      else {
        if(!ok)
          break;
      }
    }
    for(auto [k, v] : cnt) {
      ok &= !(max(0ll, (v - same[k])) != 0);
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}


