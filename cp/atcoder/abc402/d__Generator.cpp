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

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

inline long long rnd(long long l, long long r) { 
  uniform_int_distribution<long long> dis(l, r); 
  return dis(rng); 
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n = rnd(2, 10);
  int _m = 10;
  set<pair<int, int>> l;
  while (_m--) {
    int x = rnd(1, n);
    int y = rnd(1, n);
    if (x == y) {
      _m += 1;
      continue;
    }
    l.insert({x, y});
  }
  cout << n << ' ' << l.size() << '\n';
  for (auto [x, y] : l) {
    cout << x << ' ' << y << '\n';
  }
}


