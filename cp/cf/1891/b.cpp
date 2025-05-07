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
    int n, q; cin >> n >> q;
    vector<int> pos[64];
    int a[n];
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      pos[__builtin_ctz(a[i])].pb(i);
    }
    while(q--) {
      int x; cin >> x;
      for(int i = x; i <= 31; i++) {
        for(int id : pos[i]) {
          a[id] += (1 << (x - 1));
          pos[x - 1].pb(id);
        }
        pos[i].clear();
      }
    }
    for(int i = 0; i < n; i++) cout << a[i] << ' '; cout << endl;
  }
}



