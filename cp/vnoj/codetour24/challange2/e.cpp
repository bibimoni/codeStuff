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
#define int long long

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

const int N = 1e6 + 5, P = 1e6 + 5;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  auto mp = spf(N);
  vector<int> cnt(P, 0);
  int n; 
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    while(a[i] > 1) {
      int p = mp[a[i]];
      cnt[p]++;
      a[i] /= p;
    }
  }
  int tt;
  cin >> tt;
  while(tt--) {
    int x, y;
    cin >> x >> y;
    bool ok = true;
    map<int, int> f;
    while(x > 1) {
      int p = mp[x];
      f[p] += y;
      x /= p;
    }
    for(auto [k, v] : f) {
      if(cnt[k] < v) {
        ok = false;
        break;
      }
    }
    cout << ok;
  }
} 


