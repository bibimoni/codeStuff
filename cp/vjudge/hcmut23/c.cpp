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
  int a[n], b[n]; vector<int> dpUp(n), dpDown(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  b[0] = a[0]; int ans = 0;
  for(int i = 1; i < n; i++) {
    int pos = lower_bound(b, b + ans + 1, a[i]) - b;
    if((pos > 0 && b[pos - 1] != a[i]) || pos == 0) {
      b[pos] = a[i];
      ans = max(ans, pos);
    }
    dpUp[i] = ans + 1;
  }
  reverse(a, a + n); int c[n];
  c[0] = a[0], ans = 0;
  for(int i = 1; i < n; i++) {
    int pos = lower_bound(c, c + ans + 1, a[i]) - c;
    if((pos > 0 && c[pos - 1] != a[i]) || pos == 0) {
      c[pos] = a[i];
      ans = max(ans, pos);
    }
    dpDown[n - i - 1] = ans + 1;
  }
  int res = 0;
  for(int i = 0; i < n; i++) {
    res = max(res, 2 * min(dpUp[i], dpDown[i]) - 1);
  }
  cout << res;
}



