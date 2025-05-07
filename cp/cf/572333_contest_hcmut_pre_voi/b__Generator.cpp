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

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

inline long long rnd(long long l, long long r) { 
  uniform_int_distribution<long long> dis(l, r); 
  return dis(rng); 
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  // freopen("b.in", "w", stdout);
  int n = rnd(3, 10);
  cout << n << '\n';
  int h = rnd(1, 10);
  for (int i = 0; i < n; i++)  {
    cout << h << " \n"[i == n - 1];
  }
  for (int i = 0; i < n; i++) {
    cout << rnd(1, 3) << " \n"[i == n - 1];
  }
}

