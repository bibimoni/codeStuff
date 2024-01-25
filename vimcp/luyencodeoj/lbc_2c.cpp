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
const int N = (int) 1e6 + 5;
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m; cin >> n >> m;
  vector<int> a(n + 2, 0);
  for(int i = 0; i < m; i++) {
    int l, r; cin >> l >> r;
    if(l <= r) a[l]++, a[r + 1]--;
    else if(l > r) a[l]++, a[n + 1]--, a[1]++, a[r + 1]--;
  }
  int ans = 0, curr = 0;
  for(int i = 1; i <= n; i++) {
    curr += a[i];
    ans = max(ans, curr);
  }
  cout << ans;
}



