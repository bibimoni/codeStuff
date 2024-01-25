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

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, q; cin >> n >> q;
  int preX[n + 1], preY[n + 1];
  preX[0] = preY[0] = 0ll;
  string s; cin >> s; s = " " + s;
  set<pair<int, int>> st[n + 1];
  map<pair<int, int>, vector<int>> f;
  f[{0, 0}].push_back(0);
  for(int i = 1; i <= n; i++) {
    preX[i] = preX[i - 1] + (s[i] == 'L' ? -1 : (s[i] == 'R' ? 1 : 0));
    preY[i] = preY[i - 1] + (s[i] == 'U' ? 1 : (s[i] == 'D' ? -1 : 0)); 
    f[{preX[i], preY[i]}].push_back(i);
  }
  auto findInRange = [&] (int x, int y, int first, int last) {
    if(f.find({x, y}) == f.end()) return false;
    auto it = lower_bound(f[{x, y}].begin(), f[{x, y}].end(), first);
    return it != f[{x, y}].end() && *it <= last;
  };
  while(q--) {
    int x, y, l, r; cin >> x >> y >> l >> r;
    if(findInRange(x, y, 0, l - 1)) {
      cout << "YES\n";
      continue;
    }
    if(findInRange(x, y, r, n)) {
      cout << "YES\n";
      continue;
    }
    /*
      pos = pre[L - 1] + rev(pre[i]) (L <= i <= R))
      rev(pre[i]) = pre[R] - pre[i] (L <= i <= R)
      pos = pre[L - 1] + pre[R] - pre[i];
      pre[i] = pre[L - 1] + pre[R] - pos
    */
    int preXI = preX[l - 1] + preX[r] - x;
    int preYI = preY[l - 1] + preY[r] - y;
    if(findInRange(preXI, preYI, l, r)) {
      cout << "YES\n";
      continue;
    }
    cout << "NO\n";
  }
}


