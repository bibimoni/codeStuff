/**
 * Author: distiled
 */
#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#define table(...)
#endif
// #define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;  
  cin >> n >> q;
  vector<int> a(n), pos(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] -= 1;
    pos[a[i]] = i;
  }

  int cur = 1;
  for (int i = 1; i < n; i++) {
    if (pos[i] < pos[i - 1]) {
      cur += 1;
    }
  }

  auto upd = [&](int x, int d, bool check_less = true) {
    if (x > 0 && check_less && pos[x] < pos[x - 1]) {
      cur += d; 
    }
    if (x < n - 1 && pos[x] > pos[x + 1]) {
      cur += d;
    }
  };
  table(a);
  table(pos);
  dbg(cur);
  while (q--) {
    int x, y;
    cin >> x >> y;
    x -= 1;
    y -= 1;
    if (a[y] < a[x])
      swap(x, y);
    upd(a[x], -1); 
    upd(a[y], -1, a[y] != a[x] + 1); 
    dbg("cur minus", cur);
    swap(a[x], a[y]);
    pos[a[y]] = y;
    pos[a[x]] = x;
    upd(a[x], 1); 
    upd(a[y], 1, a[y] != a[x] - 1); 
    cout << cur << '\n';
    table(a);
    table(pos);
    dbg(cur);
  }

}
