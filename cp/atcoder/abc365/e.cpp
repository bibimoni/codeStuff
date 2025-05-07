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
  const int LG = 30;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int j = 0; j < LG; j++) {
    vector<array<int, 2>> cnt(n + 1, {{0, 0}});
    cnt[0][0] = 1;
    vector<int> curXor(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      curXor[i] = curXor[i - 1] ^ ((a[i] >> j) & 1);
      if (i >= 2) {
        ans += (cnt[i - 2][curXor[i] ^ 1]) * (1ll << j);
      }
      cnt[i][0] = cnt[i - 1][0] + (curXor[i] == 0);
      cnt[i][1] = cnt[i - 1][1] + (curXor[i] == 1);
    }
  }
  cout << ans << '\n';
}


