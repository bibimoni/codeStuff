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
#define int long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<pair<int, int>> a(n + 1);
  for(int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a.begin() + 1, a.end(), [&] (pair<int, int> i, pair<int, int> j) {
    return i.second < j.second;
  });
  vector<int> pre(n + 1, 0);
  for(int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] + a[i].first;
  }
  while(q--) {
    int x; 
    cin >> x;
    int l = 1, r = n, ret = 0;
    while(l <= r) {
      int m = (l + r) >> 1;
      if(a[m].second <= x) {
        ret = m;
        l = m + 1;
      }
      else {
        r = m - 1;
      }
    }
    cout << pre[ret] << '\n';
  }
}


