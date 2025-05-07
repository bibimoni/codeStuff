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
  cout << 1 << '\n';
  int n = rnd(5, 10);
  cout << n << '\n';
  int pos = rnd(1, n - 2);
  vector<int> a(n);
  a[pos] = rnd(1, 5);
  for (int i = pos + 1; i < n; i++) {
    a[i] = rnd(a[i - 1] + 1, max(a[i - 1] + 2, a[i - 1] + 20));
  } 
  for (int i = pos - 1; i >= 0; i--) {
    a[i] = rnd(a[i + 1] + 1, max(a[i + 1] + 2, a[i + 1] + 20));
  } 
  for (int i = 0; i < n; i++) {
    cout << a[i] << " \n"[i == n - 1];
  }
}

