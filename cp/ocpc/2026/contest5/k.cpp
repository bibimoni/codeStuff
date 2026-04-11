/**
 * Author: distiled
 */
#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
// #define int int64_t

const int MOD = int(1e9 + 7);

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  vector<int64_t> pre(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pre[i] = pre[i - 1] + a[i];
  }
  int64_t pn = pre[n];

  if (pn == 0) {
    int c = 0;
    for (int i = 1; i < n; i++) {
      c += pre[i] == 0;
    }
    int ans = 1;
    for (int i = 0; i < c; i++) {
      ans *= 2;
      ans %= MOD;
    }
    cout << ans << '\n';
    return 0;
  }

  int64_t apn = abs(pn);
  vector<int64_t> pn_divs;
  for (int64_t i = 1; i * i <= apn; i++) {
    if (apn % i == 0) {
      pn_divs.push_back(i);
      if (i * i != apn) {
        pn_divs.push_back(apn / i);
      }
    }
  }
  sort(pn_divs.begin(), pn_divs.end());

  vector<int> ks;
  for (int64_t div : pn_divs) {
    if (div <= n) {
      ks.push_back(int(div));
    }
  }

  vector<int64_t> valid_pre;
  for (int i = 1; i < n; i++) {
    int64_t pi = pre[i];
    if (pn > 0 && pi > 0 && pi < pn)
      valid_pre.push_back(pi);
    if (pn < 0 && pi < 0 && pi > pn)
      valid_pre.push_back(pi);
  }
  sort(valid_pre.begin(), valid_pre.end());
  valid_pre.erase(unique(valid_pre.begin(), valid_pre.end()), valid_pre.end());

  vector<int> c(ks.size(), 0);
  for (int64_t pi : valid_pre) {
    int64_t g = gcd(abs(pi), apn);
    int64_t b = apn / g;
    if (b > n)
      continue;
    int b_idx = int(lower_bound(ks.begin(), ks.end(), b) - ks.begin());
    if (b_idx < (int)ks.size() && ks[b_idx] == b) {
      c[b_idx] += 1;
    }
  }

  vector<int> cnt(ks.size(), 0);
  for (int i = 0; i < int(ks.size()); i++) {
    for (int j = i; j < int(ks.size()); j++) {
      if (ks[j] % ks[i] == 0) {
        cnt[j] += c[i];
      }
    }
  }

  vector<int> k;
  for (int i = 0; i < int(ks.size()); i++) {
    if (cnt[i] >= ks[i] - 1) {
      k.push_back(ks[i]);
    }
  }

  int ans = 0;
  for (int ck : k) {
    vector<int> dp(ck);
    dp[0] = 1;
    int64_t tar = pn / ck;
    for (int i = 1; i < n; i++) {
      int64_t pi = pre[i];
      if (pn > 0 && !(pi < pn && pi > 0))
        continue;
      if (pn < 0 && !(pi > pn && pi < 0))
        continue;
      if (pi % tar != 0)
        continue;
      int64_t t = pi / tar;
      if (t > 0 && t < ck) {
        dp[t] += dp[t - 1];
        if (dp[t] >= MOD) {
          dp[t] -= MOD;
        }
      }
    }
    ans += dp[ck - 1];
    if (ans >= MOD) {
      ans -= MOD;
    }
  }
  cout << ans << '\n';
}
