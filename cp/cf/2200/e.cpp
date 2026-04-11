/**
 * Author: distiled
 */
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
// #define int int64_t

// Computing smallest prime factor as sieve in O(nloglogn)
// Largest prime factor can be computed by removing (a[j] == 0) condition
vector<int> spf(int n) {
  n++;
  vector<int> a(n);
  a[1] = 1;
  for (int i = 2; i < n; i++) {
    if (a[i] == 0) {
      a[i] = i;
      for (int j = 2 * i; j < n; j += i) {
        if (a[j] == 0)
          a[j] = i;
      }
    }
  }
  return a;
}

const int N = 1e6;
auto mnpr = spf(N + 1);

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    if (is_sorted(a.begin(), a.end())) {
      cout << "Bob\n";
      continue;
    }
    bool ok = false;
    vector<int> b;
    for (int i = 1; i <= n; i++) {
      int x = a[i];
      int cnt = 0;
      int p = 1;
      while (x != 1) {
        p = mnpr[x];
        cnt += p >= 2;
        while (x % p == 0) {
          x /= p;
        }
      }
      if (cnt > 1) {
        ok = true;
      }
      b.push_back(p);
    }

    if (ok) {
      cout << "Alice\n";
    } else if (is_sorted(b.begin(), b.end())) {
      cout << "Bob\n";
    } else {
      cout << "Alice\n";
    }
  }
}
