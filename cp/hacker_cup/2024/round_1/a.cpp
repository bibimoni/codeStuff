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
  freopen("subsonic_subway_input.txt", "r", stdin);
  freopen("a.txt", "w", stdout);
  int tt;
  cin >> tt;
  for (int ttt = 1; ttt <= tt; ttt++) {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i].first >> a[i].second;
    }
    vector<pair<long double, long double>> s(n + 1);
    for (int i = 1; i <= n; i++) {
      s[i].first = (long double)i / (long double)a[i].second;
      if (a[i].first != 0)
        s[i].second = (long double)i / (long double)a[i].first;
      else 
        s[i].second = 1e9;
    }
    sort(s.begin() + 1, s.end(), [&] (pair<long double, long double> i, pair<long double, long double> j) {
      if (i.first != j.first)
        return i.first > j.first;
      return i.second < j.second;
    });
    long double ans = s[1].first;
    bool ok = true;
    for (int i = 1; i <= n; i++) {
      if (ans > s[i].second) {
        ok = false;
      }
    }
    cout << "Case #" << ttt << ": ";
    if (ok)
      cout << fixed << setprecision(9) << ans;
    else {
      cout << -1;
    } 
    cout << "\n";
  }
}


