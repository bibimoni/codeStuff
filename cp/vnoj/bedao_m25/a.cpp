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

const int MOD = int(1e9) + 7;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> sum(2), cnt(2);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    (sum[a[i] % 2] += a[i]) %= MOD;
    cnt[a[i] % 2] += 1;
    (ans += (a[i] * cnt[1 ^ (a[i] % 2)]) % MOD + sum[1 ^ (a[i] % 2)]) %= MOD;
  }
  cout << ans << '\n';
}


