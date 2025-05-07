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
#define all(x)         x.begin(), x.end()

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt; 
  cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n;
    vector<vector<int>> idx(n + 1);
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i], idx[a[i]].push_back(i);
    cin >> m;
    set<int> s;
    vector<int> seg(n + 1);
    seg[n] += n;
    s.insert({-1, n});
    auto add = [&] (int r, int i) {
      int pos1 = *s.lower_bound(i);
      int pos2 = *prev(s.lower_bound(i));
      seg[pos1 - pos2 - 1] -= r;
      seg[i - pos2 - 1] += r;
      seg[pos1 - i - 1] += r;
      s.insert(i);
    };

    for(int i = n; i >= 1; i--) {
      for(auto j : idx[i]) add(i, j);
    }
    int ans = 0; 
    for(int i = n; m > 0 && i > 0; i--) {
      int tmp = min(seg[i], m / i);
      ans += tmp * (i - 1);
      m -= tmp * i;
      if(tmp != seg[i] && m  > 0) {
        ans += m - 1;
        m = 0;
      }
    }
    cout << ans << '\n';
  }
}


