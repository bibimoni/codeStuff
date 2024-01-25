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
const int INF = (int) 1e18;
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n; cin >> n;
    int a[n], m = INF, M = 0;
    for(int i = 0; i < n; i++) cin >> a[i], m = min(m, a[i]), M = max(M, a[i]);
    int ans = 0; 
    if(n == 1 || m == M) {
      cout << "0\n";
      continue;
    }
    vector<int> res;
    while(abs(M - m) > 1) {
      if(m % 2 == 1 && M % 2 == 0) {
        if(res.size() < n) res.push_back(1);
        m = (m + 1) / 2;
        M /= 2;
      }
      else {
        M /= 2;
        m /= 2;
        if(res.size() < n) res.push_back(0);
      }
      dbg(res);
      ans++;
    }
    cout << ans + (!(m == M)) << '\n';
    if(ans + (!(m == M)) <= n) {
      for(int i : res) cout << i << ' ';
      if(m != M) {
        cout << (M & 1 ? 0 : 1) << ' '; 
      } 
      cout << '\n';
    }
  }
}


