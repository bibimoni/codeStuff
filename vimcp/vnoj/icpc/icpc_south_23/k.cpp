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
  int n; cin >> n;
  vector<int> l(n + 2, 0), r(n + 2, 0), a(n + 1);
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++) {
    l[i] = min(l[i - 1] + 1, a[i]);
  }
  for(int i = n; i >= 1; i--) {
    r[i] = min(r[i + 1] + 1, a[i]);
  }
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    ans = max(ans, min(l[i], r[i]));
  }
  cout << ans;
}



