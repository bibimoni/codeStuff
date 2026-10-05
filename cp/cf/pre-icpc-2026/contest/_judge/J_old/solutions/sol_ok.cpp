// Correct alternative (OK): author's structure - gcd pre-filter over prefix
// sums + a sweep DP per surviving k. Divisor enumeration fixed to the
// O(min(n, sqrt|S|)) two-sided scan (full sqrt scan TLEs on many tiny tests).
#include <bits/stdc++.h>
using namespace std;

const int MOD = int(1e9 + 7);

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int TC;
  cin >> TC;
  while (TC--) {
    int n;
    cin >> n;
    vector<int64_t> a(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      pre[i] = pre[i - 1] + a[i];
    }
    int64_t pn = pre[n];

    if (pn == 0) {
      int c = 0;
      for (int i = 1; i < n; i++) c += (pre[i] == 0);
      int ans = 1;
      for (int i = 0; i < c; i++) ans = int((int64_t)ans * 2 % MOD);
      cout << ans << '\n';
      continue;
    }

    int64_t apn = llabs(pn);
    vector<int> ks;
    int64_t r = (int64_t)sqrtl((long double)apn) + 2;
    int64_t lim = min<int64_t>(n, r);
    for (int64_t i = 1; i <= lim; i++) {
      if (apn % i == 0) {
        if (i <= n) ks.push_back((int)i);
        int64_t co = apn / i;
        if (co != i && co <= n) ks.push_back((int)co);
      }
    }
    sort(ks.begin(), ks.end());
    ks.erase(unique(ks.begin(), ks.end()), ks.end());

    vector<int64_t> valid_pre;
    for (int i = 1; i < n; i++) {
      int64_t pi = pre[i];
      if (pn > 0 && pi > 0 && pi < pn) valid_pre.push_back(pi);
      if (pn < 0 && pi < 0 && pi > pn) valid_pre.push_back(pi);
    }
    sort(valid_pre.begin(), valid_pre.end());
    valid_pre.erase(unique(valid_pre.begin(), valid_pre.end()), valid_pre.end());

    vector<int> c(ks.size(), 0);
    for (int64_t pi : valid_pre) {
      int64_t g = gcd(llabs(pi), apn);
      int64_t b = apn / g;
      if (b > n) continue;
      int b_idx = int(lower_bound(ks.begin(), ks.end(), (int)b) - ks.begin());
      if (b_idx < (int)ks.size() && ks[b_idx] == b) c[b_idx] += 1;
    }

    vector<int> cnt(ks.size(), 0);
    for (int i = 0; i < (int)ks.size(); i++)
      for (int j = i; j < (int)ks.size(); j++)
        if (ks[j] % ks[i] == 0) cnt[j] += c[i];

    int ans = 0;
    for (int idx = 0; idx < (int)ks.size(); idx++) {
      if (cnt[idx] < ks[idx] - 1) continue;
      int ck = ks[idx];
      vector<int> dp(ck);
      dp[0] = 1;
      int64_t tar = pn / ck;
      for (int i = 1; i < n; i++) {
        int64_t pi = pre[i];
        if (pn > 0 && !(pi < pn && pi > 0)) continue;
        if (pn < 0 && !(pi > pn && pi < 0)) continue;
        if (pi % tar != 0) continue;
        int64_t t = pi / tar;
        if (t > 0 && t < ck) {
          dp[t] += dp[t - 1];
          if (dp[t] >= MOD) dp[t] -= MOD;
        }
      }
      ans += dp[ck - 1];
      if (ans >= MOD) ans -= MOD;
    }
    cout << ans << '\n';
  }
}
