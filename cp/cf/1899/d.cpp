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
#define all(x)         x.begin(), x.end()

int C(int n, int k) {
  double res = 1;
  for(int i = 1; i <= k; i++) {
    res = res * (n - k + i) / i;
  }
  return (int) res;
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--){
    int n; cin >> n;
    int a[n];
    map<int, int> f;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      f[a[i]]++;
    }
    int ans = 0;
    for(auto [p, v] : f) {
      if(v >= 2)
        ans += C(v, 2);
    }
    ans += f[1] * f[2];
    cout << ans << '\n';
  }
}


