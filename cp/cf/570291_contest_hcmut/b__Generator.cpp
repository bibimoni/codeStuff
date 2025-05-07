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
  int n = rnd(1, 20), m = rnd(1, n);
  cout << n << ' ' << m << '\n';
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    // a[i] = rnd(1, n);
    a[i] = i + 1;
  } 
  shuffle(a.begin(), a.end(), rng);
  vector<int> b(m);
  vector<int> p(n);
  iota(p.begin(), p.end(), int(0));
  shuffle(p.begin(), p.end(), rng);
  vector<int> t(m);
  for (int i = 0; i < m; i++) {
    t[i] = p[i];
  }
  sort(t.begin(), t.end());
  // dbg(t);
  for (int i = 0; i < m; i++) {
    b[i] = a[t[i]];
  }
  for (int i = 0; i < n; i++) {
    cout << a[i] << " \n"[i == n - 1];
  }
  for (int i = 0; i < m; i++) {
    cout << b[i] << " \n"[i == m - 1];
  }
}

