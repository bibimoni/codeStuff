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
  const int B = int(50);
  int x = rnd(0, B), y = rnd(0, B), xe = rnd(0, B), ye = rnd(0, B);
  int n = rnd(0, int(10));
  cout << x << ' ' << y << '\n' << xe << ' ' << ye << '\n' << n << '\n';
  for (int i = 0; i < n; i++) {
    vector<char> c = {'R', 'L', 'D', 'U'};
    cout << c[rnd(0, 3)];
  }
}

