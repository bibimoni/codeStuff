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
  int tt;
  cin >> tt;
  while (tt--) {
    auto ask = [&] (int a, int b, int c) -> int {
      cout << "? " << a << ' ' << b << ' ' << c << '\n';
      cout.flush();
      int x;
      cin >> x;
      return x;
    };
    int i = 1, j = 2, k = 3;
    int x = ask(i, j, k);
    while (x != 0) {
      int v = rnd(0, 2);
      if (v == 0) {
        i = x;
      } else if (v == 1) {
        j = x;
      } else {
        k = x;
      }
      x = ask(i, j, k);
    }
    cout << "! " << i << ' ' << j << ' ' << k << '\n';
    cout.flush();
  }
}

