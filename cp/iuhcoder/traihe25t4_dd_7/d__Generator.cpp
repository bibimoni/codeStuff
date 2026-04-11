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
#define int int64_t
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n = rnd(3, 6), m = rnd(3, 5);
  cout << n << ' ' << m << '\n';
  for (int i = 0; i < m; i++) {
    cout << rnd(0, n - 1) << ' ' << rnd(0, n - 1) << ' ' << rnd(1, 100) << '\n';
  }
}
