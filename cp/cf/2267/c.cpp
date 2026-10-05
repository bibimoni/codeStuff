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

const int MX = (int)3e5 + 5;
vector<int> cnt(MX + 1);

signed main() {
  auto mnp = spf(MX);
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    vector<int> pr;
    for (int i = 0; i < n; i++) {
      int val = a[i];
      while (val != 1) {
        int p = mnp[val];
        while (val % p == 0) {
          val /= p;
        }
        cnt[p] += a[i] / p;
        pr.push_back(p);
      } 
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
      int g = gcd(a[i], x);
      dbg(g);
      while (g != 1) {
        int p = mnp[g];
        while (g % p == 0) {
          g /= p;
        }
        dbg(p, cnt[p]);
        ans = max(ans, p * cnt[p]);
      } 
    }

    for (int p : pr) {
      cnt[p] = 0;
    }

    cout << ans << '\n';
  } 
}
