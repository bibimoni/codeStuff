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


signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<int> divs;
    for(int i = 1; i * i <= n; i++) {
      if(n % i == 0) {
        divs.push_back(i);
        if(n / i != i) divs.push_back(n / i);
      }
    }
    auto check = [&] (int l) {
      if(l == n) return true;
      int g = 0;
      for(int i = 1; i + l <= n; i++) {
        g = __gcd(g, abs(a[i] - a[i + l]));
      }
      return g != 1;
    };
    int ans = 0;
    for(int div : divs) {
      ans += check(div);
    }
    cout << ans << '\n';
  }
}


