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
  int l, r;
  cin >> l >> r;

  auto len = [&] (int num) -> int {
    int ret = 0;
    while (num) {
      ret += 1;
      num /= 10;
    }
    return ret;
  };

  auto pwr = [&] (int x, int p) -> int {
    int ret = 1;
    while (p--) {
      ret *= x;
    }
    return ret;
  };
  auto to_v = [&] (int num) -> vector<int> {
    vector<int> ret;
    while (num) {
      ret.push_back(num % 10);
      num /= 10;
    }
    return ret;
  };
  vector dp(20, vector (10, vector(2, vector(2, -1))));
  auto calc = [&] (auto &&self, vector<int> &num, int n, int b, int i, bool lz, int t) -> int {
    if (i == n) {
      return 1;
    }
    if (b != -1 && dp[i][b][lz][t] != -1) {
      return dp[i][b][lz][t];
    }
    int ans = 0;
    int ub = (t ? num[i] : 9);
    for (int dig = 0; dig <= ub; dig++) {
      if (dig > b && dig != 0) {
        continue;
      }
      if (dig > b && dig == 0 && lz == 0) {
        continue;
      }
      bool is_lz = lz & dig == 0;
      int nb = (is_lz ? -1 : dig - 1);
      dbg(is_lz)
      ans += self(self, num, n, nb, i + 1, is_lz, t & (dig == ub));
    }
    dbg(b, lz, t);
    if (b != -1) {
      return (dp[i][b][lz][t] = ans);
    }
  };
  auto rv = to_v(r), lv1 = to_v(l - 1);
  int rr = calc(calc, rv, rv.size(), -1, 0, 1, 1);
  dbg(rr);
  // int l1 = calc(calc, lv1, lv1.size(), -1, 0, 1, 1);
  // dbg(rr, l1);
  // cout << rr << ' ' << l1;
}


