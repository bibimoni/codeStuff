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
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i].first;
    }
    for (int i = 1; i <= n; i++) {
      cin >> a[i].second;
    }
    sort(a.begin(), a.end());
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
      p[i] = p[i - 1] + a[i].first;
    }
    int ans = 0;
    for (int i = 2; i <= n; i++) {
      if (a[i - 1].first + 1 == a[i].first) {
        int q2 = min(a[i - 1].second, m / a[i - 1].first);
        int tmp = m - q2 * a[i - 1].first;
        int q1 = min(a[i].second, tmp / a[i].first);
        int b = min({a[i].second - q1, tmp - q1 * a[i].first, q2});
        int nq1 = q1 + b, nq2 = q2 - b;
        ans = max(ans, nq1 * a[i].first + nq2 * a[i - 1].first);
      } else {
        int q1 = min(a[i].second, m / a[i].first);
        ans = max(ans, q1 * a[i].first);
      }
    }
    cout << ans << '\n';
  }
}


