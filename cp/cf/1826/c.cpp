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
#define int            long long

// Computing smallest prime factor as sieve in O(nloglogn)
// Largest prime factor can be computed by removing (a[j] == 0) condition
vector<int> spf(int n) {
  n++;
  vector<int> a(n);
  a[1] = 1;
  for (int i = 2; i < n; i++) {
    if (a[i] == 0) {
      a[i]  = i;
      for (int j = 2 * i; j < n; j += i) {
        if (a[j] == 0) a[j] = i;
      }
    }
  }
  return a;
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  auto minPrime = spf((int) 1e6 + 5);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    if(m == 1 || n == 1) {
      cout << "YES\n";
      continue;
    }
    int tmp = n;
    bool ok = true;
    while(tmp > 1) {
      int p = minPrime[tmp];
      if(p <= m) {
        ok = false;
        break;
      }
      while(tmp % p == 0) {
        tmp /= p;
      }
    }
    if(tmp != 1) {
      ok &= !(tmp <= m);
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}


