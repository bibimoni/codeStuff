// WA: the tempting greedy "more segments is always better" - only counts the
// single division into the maximal number of segments (minimal |segment sum|),
// and for S == 0 assumes you must cut at every zero prefix (1 way).
// Both are wrong: ways(k) for smaller k also count, and zero-prefix cuts are
// a free subset (2^c ways).
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
      cout << 1 << '\n'; // wrong: should be 2^c
      continue;
    }
    ll apn = llabs(pn);
    int kmax = 1;
    for (ll i = 1; i <= (ll)min<ll>(n, apn); i++) // divisor scan, keep max <= n
      if (apn % i == 0) {
        if (i <= n) kmax = max(kmax, (int)i);
        if (apn / i <= n) kmax = max(kmax, (int)(apn / i));
      }
    // wrong: divisions into fewer than kmax segments are also valid and counted
    ll tar = pn / kmax;
    unordered_map<ll, int> cnt;
    for (int i = 1; i < n; i++) cnt[pre[i]]++;
    ll ways = 1;
    for (ll j = 1; j < kmax; j++) {
      auto it = cnt.find(j * tar);
      if (it == cnt.end()) { ways = 0; break; }
      ways = ways * it->second % MOD;
    }
    cout << ways << '\n';
  }
  return 0;
}
