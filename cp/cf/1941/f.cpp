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
    int n, m, k;
    cin >> n >> m >> k;
    int a[n + 1], d[m + 1], f[k + 1];
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for(int i = 1; i <= m; i++) {
      cin >> d[i];
    }
    for(int i = 1; i <= k; i++) {
      cin >> f[i];
    }
    sort(d + 1, d + m + 1);
    sort(f + 1, f + k + 1);
    vector<int> diff(n);
    for(int i = 1; i < n; i++) {
      diff[i] = a[i + 1] - a[i];
    }
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin() + 1, order.end(), [&] (int i, int j) {
      return diff[i] > diff[j];
    }); 
    int l = a[order[1]], r = a[order[1] + 1];
    int secondBest = (n > 2 ? diff[order[2]] : 0);
    int ans = diff[order[1]];
    int j = k;
    for(int i = 1; i <= m; i++) {
      while(j > 1 && d[i] + f[j - 1] >= ((l + r) >> 1)) {
        j--;
      }
      if(d[i] + f[j] > l && d[i] + f[j] < r) {
        ans = min(ans, max({r - d[i] - f[j], d[i] + f[j] - l, secondBest}));
      }
      if(j > 1) {
        if(d[i] + f[j - 1] > l && d[i] + f[j - 1] < r) {
          ans = min(ans, max({r - d[i] - f[j - 1], d[i] + f[j - 1] - l, secondBest}));
        } 
      }
    }
    cout << ans << '\n';
  }
}


