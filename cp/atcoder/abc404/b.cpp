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
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  vector<string> t(n);
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  auto rot = [&] (vector<string> a) -> vector<string> {
    vector<string> ret = a;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        ret[i][j] = a[j][n - i - 1];
      }
    }
    return ret;
  };
  auto calc = [&] (vector<string> cur) -> int {
    int ret = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        ret += s[i][j] != cur[i][j];
      }
    }
    return ret;
  };

  int ans = calc(t);
  t = rot(t);
  ans = min(ans, 1 + calc(t));
  t = rot(t);
  ans = min(ans, 2 + calc(t));
  t = rot(t);
  ans = min(ans, 3 + calc(t));
  cout << ans << '\n';
}


