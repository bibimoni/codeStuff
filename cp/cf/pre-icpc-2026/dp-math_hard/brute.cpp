// Local-only exponential brute force for cross-checking (never uploaded).
// n <= 22: enumerates all 2^(n-1) cut masks, checks equal segment sums.
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
    vector<ll> a(n), pre(n + 1, 0);
    for (auto &x : a) cin >> x;
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i - 1];
    ll ans = 0;
    for (int mask = 0; mask < (1 << (n - 1)); mask++) {
      bool okmask = true;
      ll first = -1; bool set = false;
      int start = 0;
      for (int i = 1; i <= n && okmask; i++) {
        bool cut = (i == n) || (mask >> (i - 1)) & 1;
        if (!cut) continue;
        ll s = pre[i] - pre[start];
        if (!set) { first = s; set = true; }
        else if (s != first) okmask = false;
        start = i;
      }
      if (okmask) { ans++; if (ans >= MOD) ans -= MOD; }
    }
    cout << ans << '\n';
  }
  return 0;
}
