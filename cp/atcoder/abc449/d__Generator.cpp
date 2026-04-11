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
  int l = rnd(-10, 10);
  int r = rnd(l, 10);
  int d = rnd(-10, 10);
  int u = rnd(d, 10);
  cout << l << ' ' << r << ' ' << d << ' ' << u;
}
