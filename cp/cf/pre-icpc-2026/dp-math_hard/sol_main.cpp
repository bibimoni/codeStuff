// Model solution.
// Let pre[i] = a1+...+ai, S = pre[n].
//  S == 0: every segment must sum to 0; any subset of the indices i<n with
//          pre[i]==0 works as cut set -> answer = 2^c, c = #{i<n : pre[i]==0}.
//  S != 0: a division into k segments forces segment sum S/k, so k | S and
//          k <= n. For such k, with t = S/k, cuts c_1<...<c_{k-1} must satisfy
//          pre[c_j] == j*t  (chain - order matters when values can be negative).
//          ways(k) = # of such chains, computed by a left-to-right sweep:
//          dp[j] += dp[j-1] whenever pre[i] == j*t.  k=1 contributes 1.
// Candidate k are divisors of |S| up to n; k and |S|/k both appear scanning
// i in [1, min(n, sqrt|S|)], so total divisor work over the input is O(sum n).
// A cheap viability precheck (all k-1 multiples of t present as prefix values)
// keeps the O(n) sweep for k that can actually contribute.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

struct chash {
  static uint64_t mix(uint64_t x) {
    x += 0x9e3779b97f4a7c15ULL;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
    x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
    return x ^ (x >> 31);
  }
  size_t operator()(ll x) const { return mix((uint64_t)x); }
};

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
    unordered_map<ll, int, chash> cnt;
    cnt.reserve(2 * n + 10);
    for (int i = 1; i < n; i++) cnt[pre[i]]++;
    ll ans = 0;
    vector<int> dp(n + 1, 0);
    for (int k : ks) {
      ll tar = pn / k;
      bool viable = true;
      for (ll j = 1; j < k; j++)
        if (!cnt.count(j * tar)) { viable = false; break; }
      if (!viable) continue;
      // ordered chain DP over the prefix positions
      fill(dp.begin(), dp.begin() + k + 1, 0);
      dp[0] = 1;
      for (int i = 1; i < n; i++) {
        if (pre[i] % tar != 0) continue;
        ll j = pre[i] / tar;
        if (j >= 1 && j < k) {
          dp[j] += dp[j - 1];
          if (dp[j] >= MOD) dp[j] -= MOD;
        }
      }
      ans += dp[k - 1];
      if (ans >= MOD) ans -= MOD;
    }
    cout << ans << '\n';
  }
  return 0;
}
