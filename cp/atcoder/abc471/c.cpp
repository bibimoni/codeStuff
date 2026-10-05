/**
 * Author: distiled
 */
#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
// #define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  set<int> a;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a.insert(x);
  }

  int64_t ans = 0;
  int cur = 0;
  a.insert(cur);
  while (a.size() > 1) {
    auto it = a.find(cur); 
    auto l = prev(it);
    auto r = next(it);
    const int64_t INF = 4e9;
    int64_t dl = INF, dr = INF;
    if (it != a.begin()) {
      dl = cur - *l;
    }
    if (r != a.end()) {
      dr = *r - cur;
    }
    a.erase(cur);

    if (dl <= dr) {
      cur = *l;
    } else {
      cur = *r;
    }
    ans += min(dl, dr);
  }
  
  cout << ans;
}
