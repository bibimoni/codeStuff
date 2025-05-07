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
  vector<int> a(n + 1);
  vector<vector<int>> occupied(n + 1); 
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> w(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
    occupied[a[i]].push_back(w[i]);
  }
  int ans = 0;
  for (auto &p : occupied) {
    if (!p.size()) {
      continue;
    }
    ans += accumulate(p.begin(), p.end(), 0ll) - *max_element(p.begin(), p.end());
  }
  cout << ans << '\n';
}


