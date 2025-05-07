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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int before = 0;
  if (k > n / 2) {
    for (int i = 0; i < n; i++) {
      before ^= a[i];
    }
    k = n - k;
  }
  int ans = -1;

  auto dfs = [&] (this auto &&self, int i, int cnt, int dep, int cur) -> void {
    if (cnt == k) {
      ans = max(ans, cur);
      return;
    }
    self(i + 1, cnt + 1, dep + 1, cur ^ a[i]);
    if (n - dep - 1 + cnt >= k) {
      self(i + 1, cnt, dep + 1, cur);
    }
  };
  
  dfs(0, 0, 0, before);
  cout << ans;
}


