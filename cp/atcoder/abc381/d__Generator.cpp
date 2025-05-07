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
  int n = 20;
  cout << n << '\n';
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    int t = rnd(0, 3);
    if (t == 0 && i > 0) {
      a[i] = a[i - 1];
    } else if (t == 1 && i < n - 1) {
      a[i] = rnd(0, 10);
      a[i + 1] = a[i];
      i += 1;
    } else {
      a[i] = rnd(0, 10);
    }
  } 
  for (int i = 0; i < n; i++) {
    cout << a[i] << " \n"[i == n - 1];
  }
}

