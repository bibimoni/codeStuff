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
  int m, n; cin >> n >> m;
  int a[n], b[m];
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < m; i++) cin >> b[i];
  int posA[20] = {0}, posB[20] = {0};
  for(int i = 0; i < n; i++) {
    int x = a[i], pos = 0;
    while(x && pos < 20) {
      posA[pos++] += x & 1; x >>= 1;
    }
  }
  for(int i = 0; i < m; i++) {
    int y = ~b[i], pos = 0;
    while(y && pos < 20) {
      posB[pos++] += y & 1; y >>= 1;
    }
  }
  int ans = 0;
  for(int pos = 0; pos < 20; pos++) {
    ans += posA[pos] * posB[pos] * (1 << pos);
  }
  cout << ans;
}




