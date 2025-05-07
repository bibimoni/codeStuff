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
#define int long long

const int INF = (int) 1e18;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<int> ans(n + 1, 0);
    ans[1] = a[1];
    multiset<int> sMax;
    multiset<int, greater<int>> sMin;
    for(int i = 1; i <= 3; i++) {
      sMax.insert(a[i]);
    }
    sMin.insert(*sMax.begin());
    sMax.erase(sMax.begin());
    int hi = accumulate(sMax.begin(), sMax.end(), 0ll), lo = accumulate(sMin.begin(), sMin.end(), 0ll);    // dbg(dpMin)
    ans[3] = hi - lo;
    dbg(hi, lo, sMax, sMin);
    for(int i = 4; i <= n; i++) {
      if(i % 2 == 0) {
        sMin.insert(a[i]);
        lo += a[i];
        sMax.insert(*sMin.begin());
        lo -= *sMin.begin();
        hi += *sMin.begin();
        sMin.erase(*sMin.begin());
      }
      else {
        sMax.insert(a[i]);
        hi += a[i];
        sMin.insert(*sMax.begin());
        hi -= *sMax.begin();
        lo += *sMax.begin();
        sMax.erase(*sMax.begin());
        ans[i] = hi - lo;
      }
      dbg(hi, lo, sMax, sMin);
    }
    while(q--) {
      int k;
      cin >> k;
      cout << ans[k] << ' ';
    }
    cout << '\n';
  }
}

