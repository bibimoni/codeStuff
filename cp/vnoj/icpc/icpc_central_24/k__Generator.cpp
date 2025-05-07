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
  int n = rnd(100, 100);
  int k = 15;
  set<pair<int, int>> st;
  while (st.size() < k) {
    int x, y;
    for ( ; ;) {
      x = rnd(1, n);
      y = rnd(1, n);
      if (st.find({x, y}) == st.end()) {
        st.insert({x, y});
        break;
      }
    }
  }
  cout << n << '\n';
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (st.find(pair<int, int>{i + 1, j + 1}) != st.end()) {
        cout << "*";
      } else {
        cout << rnd(1, 100);
      }
      cout << " \n"[j == n - 1];
    }
}

