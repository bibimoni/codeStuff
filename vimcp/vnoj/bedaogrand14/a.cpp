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
  int a[n + 1]; 
  for(int i = 0; i <= n; i++) {
    cin >> a[i];
  }
  sort(a, a + n + 1);
  for(int i = 1; i <= n; i++) {
    if(a[i] - 1 != a[i - 1]) continue;
    if(a[i] - 1 == a[i - 1]) cout << a[i] << ' ' << a[i - 1];
    break;
  }
}



