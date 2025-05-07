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
#define int long long

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

inline long long rnd(long long l, long long r) { 
  uniform_int_distribution<long long> dis(l, r); 
  return dis(rng); 
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n = 15;
  cout << n << '\n';
  for(int i = 0; i < n; i++) {
    cout << rnd(-50, 50) << " \n"[i == n - 1];
  }
  vector<pair<int, int>> que;
  for(int i = 1; i <= n; i++) {
    for(int j = i; j <= n; j++) {
      que.push_back({i, j});
    }
  }
  cout << que.size() << '\n';
  for(auto [i, j] : que) {
    cout << i << ' ' << j << '\n';
  }
} 

