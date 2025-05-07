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
  int m = rnd(1, 1);
  string s;
  for (int i = 0; i < m; i++) {
    s += char(rnd(0, 25) + 'A');
  }
  // cout << m << '\n' << s << '\n';
  s += s;
  int pos = rnd(0, s.size());
  string t = "";
  int n = s.size() + 1;
  bool f = false;
  for (int i = 0; i < n; i++) {
    if (i == pos) {
      t += char(rnd(0, 25) + 'A');
      f = true;
    } else if (!f) {
      t += s[i];
    } else {
      t += s[i - 1];
    }
  }
  cout << n << '\n' << t;
}

