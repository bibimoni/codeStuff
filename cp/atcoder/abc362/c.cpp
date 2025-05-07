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
  vector<pair<int, int>> seg(n);
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    seg[i] = {l, r};
    if (r < 0) {
      ans[i] = r;
    } else if (l > 0) {
      ans[i] = l;
    } else if (l * r <= 0) {
      ans[i] = 0;
    }
  }
  int curr = accumulate(ans.begin(), ans.end(), 0ll);
  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  vector<int> diff(n);
  for (int i = 0; i < n; i++) {
    diff[i] = max(abs(ans[i] - seg[i].second), abs(ans[i] - seg[i].first));
  }
  sort(p.begin(), p.end(), [&] (int i, int j) {
    return diff[i] > diff[j];
  });
  for (int id = 0; id < n; id++) {
    int i = p[id];
    if (curr >= 0) {
      int g = ans[i] - seg[i].first;
      int k = min(g, curr);
      ans[i] -= k;
      curr -= k;
    } else {
      int g = seg[i].second - ans[i];
      int k = min(g, -curr);
      ans[i] += k;
      curr += k;      
    }
  }
  if (curr == 0) {
    cout << "Yes\n";
    for (int i : ans) {
      cout << i << ' ';
    }
  } else {
    cout << "No\n";
  }
}


