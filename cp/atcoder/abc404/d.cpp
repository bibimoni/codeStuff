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
  vector<int> c(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }

  vector<vector<int>> ani(n + 1);

  vector<vector<int>> a(m + 1);
  for (int i = 1; i <= m; i++) {
    int k;
    cin >> k;
    for (int j = 1; j <= k; j++) {
      int x;
      cin >> x;
      a[i].push_back(x);
      ani[x].push_back(i);
    }
  }

  int lim = pow(int(3), n) - 1;
  int ans = int(1e18);
  for (int mask = 0; mask <= lim; mask++) {
    int cur = 0;
    int tmp = mask;
    vector<int> cnt(m + 1, 0);
    int i = 1;
    do {
      int val = tmp % 3;
      for (int x : ani[i]) {
        cnt[x] += val;
      }
      cur += c[i] * val;
      tmp /= 3;
      i += 1;
    } while (tmp > 0);
    
    bool ok = true;
    for (int i = 1; i <= m; i++) {
      ok &= cnt[i] >= 2;
    }
    if (ok) {
      ans = min(ans, cur);
    }
  }
  cout << ans << '\n';
}


