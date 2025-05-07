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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<long double> b(n);
    for (int i = 0; i < n; i++) {
      b[i] = log(log(a[i]));
    }
    int i = 0, ans = 0;
    while (i < n && a[i] == 1) {
      i += 1;
    }
    i += 1;
    const long double EPS = 1e-9;
    for (; i < n; i++) {
      if (a[i] == 1) {
        ans = -1;
        break;
      }
      if (b[i - 1] - b[i] <= EPS) {
        continue;
      }
      int add = ceil((b[i - 1] - b[i] - EPS) / log(2));
      ans += add;
      b[i] += add * log(2);
    }
    cout << ans << '\n';
  }
}

