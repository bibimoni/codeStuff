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

// Get primes not greater than n in O(nloglogn)
vector<int> getprimes(int n) {
  vector<int> p;
  vector<bool> is(n + 1, 1);
  for (int i = 2; i <= n; i++) {
    if (is[i]) {
      p.push_back(i);
      for (int j = 2 * i; j <= n; j += i) is[j] = 0;
    }
  }
  return p;
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  int X = sqrt(n);
  const int N = 1e6 + 5; 
  auto primes = getprimes(N);
  int ans = 0;
  auto pow8 = [&] (int x) -> int {
    int ret = 1;
    for (int i = 0; i < 8; i++) {
      ret *= x;
    }
    return ret;
  };
  for (auto p1 : primes) {
    if (pow8(p1) <= n && p1 <= 37) {
      ans += 1;
    }
    for (int i = 0; i < primes.size(); i++) {
      if (primes[i] >= p1 || primes[i] * p1 > X) {
        break;
      }
      ans += 1;
    }
  }
  cout << ans << '\n';
}


