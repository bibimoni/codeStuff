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
  int n, m;
  cin >> n >> m;
  vector<int> x(m);
  for (int i = 0; i < m; i++) {
    cin >> x[i];
    x[i] -= 1;
  }
  vector<int> a(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }
  vector<int> p(m);
  iota(p.begin(), p.end(), 0);
  sort(p.begin(), p.end(), [&] (int i, int j) {
    return x[i] < x[j];
  });
  int stones = accumulate(a.begin(), a.end(), int(0));
  if (stones != n) {
    cout << "-1\n";
    return 0;
  }
  auto calc = [&] (int l, int r) -> int {
    l -= 1;
    return r * (r + 1) / 2 - l * (l + 1) / 2;
  };
  int cur = -1, ans = 0;
  bool ok = true;
  for (int id = 0; id < m; id++) {
    int i = p[id];
    int lt = cur + 1;
    int rt = cur + a[i];
    if (lt < x[i]) {
      ok = false;
      break;
    }
    ans += calc(lt - x[i], rt - x[i]);
    cur = rt;
  }
  cout << (ok ? ans : -1) << '\n';
}


