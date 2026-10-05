// TL: correct but slow. For every k in [1, n] with k | S it runs the chain DP
// with an explicit inner loop over j -> O(n*k) per candidate k. Fast on random
// tests (few divisors) but quadratic on divisor-rich max tests, where the
// intended solution's viability precheck skips the sweeps entirely.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<ll> pre(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      ll x;
      cin >> x;
      pre[i] = pre[i - 1] + x;
    }
    ll pn = pre[n];
    if (pn == 0) {
      int c = 0;
      for (int i = 1; i < n; i++) c += (pre[i] == 0);
      ll ans = 1;
      for (int i = 0; i < c; i++) ans = ans * 2 % MOD;
      cout << ans << '\n';
      continue;
    }
    ll ans = 0;
    vector<int> dp(n + 1, 0);
    for (int k = 1; k <= n; k++) {
      if (pn % k != 0) continue;
      ll tar = pn / k;
      fill(dp.begin(), dp.begin() + k + 1, 0);
      dp[0] = 1;
      for (int i = 1; i < n; i++)
        for (ll j = 1; j < k; j++)
          if (pre[i] == j * tar) {
            dp[j] += dp[j - 1];
            if (dp[j] >= MOD) dp[j] -= MOD;
          }
      ans = (ans + dp[k - 1]) % MOD;
    }
    cout << ans << '\n';
  }
  return 0;
}
