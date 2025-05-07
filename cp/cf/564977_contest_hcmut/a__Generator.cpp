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
  int n = 5, m = 6;
  cout << n << ' ' << m << '\n';
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << char(rnd(0, 25) + 'a');
    }
    cout << '\n';
  }
}

