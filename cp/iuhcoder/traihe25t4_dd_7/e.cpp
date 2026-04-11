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

const int M = 1000000;

vector<int> primes() {
  vector<int> res;
  vector<int> t(M + 1, 0);
  for (int i = 2; i <= M; i++) {
    if (t[i] == 0) {
      res.push_back(i);
      for (int j = i; j <= M; j += i) {
        t[j] = i;
      }
    }
  }
  return res;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  int n, k;

  vector<int> pr = primes();
  for (int i = 0; i < 10; i++) {
    cerr << pr[i] << " ";
  }
  cerr << endl;

  cin >> t;
  while (t--) {
    cin >> n >> k;

    int kx = k;
    int res = 1e18;

    for (int u : pr) {
      if (kx % u)
        continue;

      int cnt = 0;
      for (int tk = u; tk <= n; tk *= u) {
        cnt += n / tk;
        if (tk > 2e18 / u)
          break;
      }

      int se = 0;
      while (!(kx % u)) {
        se++;
        kx /= u;
      }
      res = min(res, cnt / se);
    }

    if (kx > 1) {
      int cnt = 0;
      // nx is prime
      for (int tk = kx; tk <= n; tk *= kx) {
        cnt += (n / tk);
        if (tk > 2e18 / kx)
          break;
      }
      res = min(res, cnt);
    }

    cout << res << endl;
  }
}
