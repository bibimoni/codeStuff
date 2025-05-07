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
  int n, k, d;
  cin >> n >> k >> d;
  vector<int> ans(n + 1);
  iota(ans.begin(), ans.end(), 0ll);
  vector<pair<int, int>> events;
  for(int i = 0; i < k; i++) {
    int l, r;
    cin >> l >> r;
    reverse(ans.begin() + l, ans.begin() + r + 1);
  }
  const int LG = 35;
  vector<vector<int>> nxt(LG, vector<int>(n + 1));
  for(int i = 1; i <= n; i++) {
    nxt[0][i] = ans[i];
  }
  d--;
  for(int j = 1; j < LG; j++) {
    for(int i = 1; i <= n; i++) {
      nxt[j][i] = nxt[j - 1][nxt[j - 1][i]];
    }
  }
  auto get = [&] (int i) -> int {
    int u = ans[i], tmp = d;
    for(int j = 32; j >= 0; j--) {
      if(tmp >= (1ll << j)) {
        u = nxt[j][u];
        tmp -= (1ll << j);
      }
    }
    return u;
  };
  for(int i = 1; i <= n; i++) {
    ans[i] = get(i);
    cout << ans[i] << ' ';
  }
}


