// WA regression witness: sol_main but "forgets" every 500th prefix index
// (i % 500 == 0). Index-targeted corruption hack; the all-ones 2*prime tests
// pin cut requirements at many individual indices, so a skipped index in the
// swept range changes the answer.
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
    ll apn = llabs(pn);
    ll r = (ll)sqrtl((long double)apn);
    while ((r + 1) * (r + 1) <= apn) r++;
    while (r * r > apn) r--;
    ll lim = min((ll)n, r);
    vector<int> ks;
    for (ll i = 1; i <= lim; i++) {
      if (apn % i == 0) {
        if (i <= n) ks.push_back((int)i);
        ll co = apn / i;
        if (co != i && co <= n) ks.push_back((int)co);
      }
    }
    sort(ks.begin(), ks.end());
    unordered_map<ll, int> cnt;
    for (int i = 1; i < n; i++) {
      if (i % 500 == 0) continue; // the "hack"
      cnt[pre[i]]++;
    }
    vector<int> dp(n + 1, 0);
    ll ans = 0;
    for (int k : ks) {
      ll tar = pn / k;
      bool viable = true;
      for (ll j = 1; j < k; j++)
        if (!cnt.count(j * tar)) { viable = false; break; }
      if (!viable) continue;
      fill(dp.begin(), dp.begin() + k + 1, 0);
      dp[0] = 1;
      for (int i = 1; i < n; i++) {
        if (i % 500 == 0) continue; // and skip here too
        if (pre[i] % tar != 0) continue;
        ll j = pre[i] / tar;
        if (j >= 1 && j < k) {
          dp[j] += dp[j - 1];
          if (dp[j] >= MOD) dp[j] -= MOD;
        }
      }
      ans = (ans + dp[k - 1]) % MOD;
    }
    cout << ans << '\n';
  }
  return 0;
}
