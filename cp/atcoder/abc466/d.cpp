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
  int n, m;
  cin >> n >> m;
  set<int> p;
  vector<int> vr(n, -1), vc(n, -1);
  for (int i = 0; i < m; i++) {
    int r, c;
    cin >> r >> c;
    r -= 1;
    c -= 1;
    if (vr[r] != -1) {
      p.erase(vr[r]);
    }
    if (vc[c] != -1) {
      p.erase(vc[c]);
    }
    vr[r] = i;
    vc[c] = i;
    p.insert(i);
  }
  cout << int(p.size());
}
