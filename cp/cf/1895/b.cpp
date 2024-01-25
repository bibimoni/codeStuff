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
#define pb             push_back
#define all(x)         x.begin(), x.end()
#define sz(x)          (int) x.size()
#define endl           '\n'
#define MULTI          int tt;cin>>tt;while(tt--)
inline int nxt() { int n; cin >> n; return n; }

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  MULTI {
    int n; cin >> n;
    int a[2 * n + 1]; for(int i = 1; i <= 2 * n; i++) cin >> a[i];
    sort(a + 1, a + 2 * n + 1);
    int ans = 0;
    vector<pair<int, int>> res;
    for(int i = 1; i < n; i ++) {
      ans += abs(a[i + 1] - a[i]) + abs(a[i + n + 1] - a[i + n]);
      res.pb({a[i], a[i + n]});  
    }
    cout << ans << endl;
    for(auto [x, y] : res) {
      cout << x << ' ' << y << endl;
    }  
    cout << a[n] << ' ' << a[2 * n] << endl;
  }
}



