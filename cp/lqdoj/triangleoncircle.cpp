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

int C(int n, int k) {
  double res = 1;
  for(int i = 1; i <= k; i++) {
    res = res * (n - k + i) / i;
  }
  return (int) res;
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, c;
  cin >> n >> c;
  vector<int> p(n);
  vector<int> t(c);
  vector<int> pre(c);
  int half = c / 2;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    t[p[i]] = 1;
  }
  sort(p.begin(), p.end());
  dbg(t);
  for (int i = 0; i < c; i++) {
    if (i == 0) 
      pre[i] = t[i];
    else 
      pre[i] = pre[i - 1] + t[i];
  }
  auto c2 = [&] (int k) -> int {
    return k * (k - 1) / 2;
  };
  auto range = [&] (int l, int r) -> int {
    if (l <= r) {
      return pre[r] - (l == 0 ? 0 : pre[l - 1]);
    }
    else {
      return pre[c - 1] - (l == 0 ? 0 : pre[l - 1]) + pre[r];
    }
  };
  int pts = accumulate(t.begin(), t.end(), 0ll);
  int ans = C(pts, 3);
  dbg(ans);
  for (int i = 0; i < c; i++) {
    int l = (i + 1) % c, r = (i + half) % c;
    dbg(range(l, r), l, r);
    dbg(c2(range(l, r)));
    ans -= c2(range(l, r));
  }
  cout << ans << '\n';
}

