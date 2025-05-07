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

const int INF = (int) 1e18;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<int> b(n + 1), pre(n + 1, 0);
    for(int i = 1; i <= n; i++) {
      cin >> b[i];
    }
    for(int i = 1; i <= n; i++) {
      pre[i] = pre[i - 1] + min(b[i], a[i]);
    }
    int ans = INF;
    for(int i = 1; i <= m; i++) {
      ans = min(ans, pre[n] - pre[i] + a[i]);
    }
    cout << ans << '\n';
  }
}

