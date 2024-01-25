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
  int res = 0;
  int a[n], b[n];
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  b[0] = a[0];
  for(int i = 1; i < n; i++) {
    int pos = lower_bound(b, b + res + 1, a[i]) - b;
    b[pos] = a[i];
    res = max(res, pos);
  }
  for(int i = 0; i <= res; i++) {
    cout << b[i] << ' ';
  }
  cout << res + 1;
}



