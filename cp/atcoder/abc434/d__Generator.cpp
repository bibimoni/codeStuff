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

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

inline long long rnd(long long l, long long r) {
  uniform_int_distribution<long long> dis(l, r);
  return dis(rng);
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n = rnd(1, 5);
  cout << n << '\n';
  const int MX = 6;
  for (int i = 0; i < n; i++) {
    int u = rnd(1, MX);
    int d = rnd(u, MX);
    int l = rnd(1, MX);
    int r = rnd(l, MX);
    cout << u << ' ' << d << ' ' << l << ' ' << r << '\n';
  }
}
