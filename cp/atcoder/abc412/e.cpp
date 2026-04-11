/**
 * Author: distiled
 */
#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int l, r;
  cin >> l >> r;
  int sqrtr = (int)sqrt(r);
  vector<int> mark(sqrtr + 1, 0);
  vector<int> primes;
  for (int i = 2; i <= sqrtr; i++) {
    if (!mark[i]) {
      primes.push_back(i);
      for (int j = i * i; j <= sqrtr; j += i) {
        mark[j] = 1;
      }
    }
  }

  int ans = 1;
  vector<int> is_prime(r - l + 1, 0);
  for (int p : primes) {
    for (int j = max(p * p, (l + p - 1) / p * p); j <= r; j += p) {
      if (j == l || is_prime[j - l] != 0) {
        continue;
      }
      is_prime[j - l] = 1;
      int x = j;
      while (x % p == 0) {
        x /= p;
      }
      ans += x == 1;
    }
  }
  for (int j = 1; j < r - l + 1; j++) {
    ans += is_prime[j] == 0;
  }

  cout << ans << '\n';
}
