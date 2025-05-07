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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> cnt;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      cnt[a[i]] += 1;
    }
    bool ok = false;
    for(auto [f, s] : cnt) {
      if(s >= k)
        ok = true;
    }
    cout << (ok ? k - 1 : n) << '\n';
  }
}


