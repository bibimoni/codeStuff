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
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  long double d = 0.0;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  a.insert(a.begin(), pair<int, int>{0, 0});
  n += 1;
  for (int i = 0; i < n; i++) {
    auto [x_1, y_1] = a[i];
    auto [x_2, y_2] = a[(i + 1) % n];
    d += (long double) sqrt((x_1 - x_2) * (x_1 - x_2) + (y_1 - y_2) * (y_1 - y_2));
  }
  cout << setprecision(9) << fixed << d << '\n';
}


