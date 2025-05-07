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
  int n = 23;
  vector<int> a(n);
  int sum = 0;
  for(int i = 0; i < n; i++) {
      int num = rnd(1, 2023);
      a[i] = num;
  }
  int start = rnd(0, n - 1);
  int end = rnd(start, n - 1);
  int rem = end - start;
  for(int i = start; i <= end; i++) {
      a[i] = rnd(1, 2024 - sum - rem);
      dbg(a[i], sum, rem);
      rem--;
      sum += a[i];
  }
  if(sum < 2024) {
      a[end] += 2024 - sum;
  }
  dbg(start, end, sum);
  dbg(a);
  bool ok = false;
  set<int> s({0});
  int curr = 0;
  for(int i = 1; i <= n; i++) {
    curr += a[i];
    if(s.find(curr - 2024) != s.end()) {
      ok = true;
    }
    s.insert(curr);
  }
  cout << (ok ? "YES\n" : "NO\n");
}

