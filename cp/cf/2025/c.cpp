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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    vector<pair<int, int>> p;
    int cur = a[1], cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (cur == a[i]) {
        cnt += 1;
      } else {
        p.push_back({cur, cnt});
        cnt = 1;
        cur = a[i];
      }
    }
    p.push_back({cur, cnt});
    int m = p.size();
    int j = 0, ans = 0, dis = 0;
    cur = 0;
    for (int i = 0; i < m; i++) {
      if (i == 0 || p[i].first == 1 + p[i - 1].first) {
        cur += p[i].second;
        dis += 1;
      } else {
        j = i;
        dis = 1;
        cur = p[i].second;
      }
      while (j < m && dis > k) {
        cur -= p[j].second;
        dis -= 1;
        j += 1;
      }
      ans = max(ans, cur);
    }
    cout << ans << '\n';
  }
}


