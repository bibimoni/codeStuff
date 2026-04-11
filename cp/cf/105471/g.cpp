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
  int mx = 1e5 + 5;
  vector<int> mi  = spf(mx);
  int q; cin >> q;
  while(q--) {
    vector<pair<int, int>> p;
    int n; cin >> n;
    if(n == 1) {
      cout << 1 << "\n";
      continue;
    }
    int c = n;
    for(int i = 2; i*i <= n; ++i) {
      if(n%i == 0) {
        int cnt = 0;
        while(n%i == 0) {
          n /= i;
          cnt++;
        }
        p.push_back({i, cnt});
      }
      
      //cout << cnt << "\n";
    }
    if(n != 1) p.push_back({n, 1}); 
    mx = (1 << p.size());
    int ans = 0;
    for(int i = 0; i < mx; ++i) {
      int u1 = 1;
      int u2 = 1;
      //int cnt = 0;
      for(int j = 0; j < p.size(); ++j) {
        if((i >> j)&1) {
          u1 *= p[j].second;
          //cnt++;
        }
        else {
          u2 *= (p[j].second + 1);
        }
      }
      //cout << "cuong\n";
      //cout << u1 << " " << u2 << "\n"; 
      ans += u1*u2;
    }
    cout << (ans+1)/2 << "\n";
  }
}
