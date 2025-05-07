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

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  int a[n + 1];
  int pre[n + 1];
  bool mark[n + 1];
  mark[0] = mark[1] = pre[0] = pre[1] = 0;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for(int i = 2; i <= n; i++) {
    mark[i] = (a[i - 1] >= a[i] && a[i] >= a[i + 1]);
    pre[i] = pre[i - 1] + mark[i];
  }
  while(q--) {
    int l, r;
    cin >> l >> r;
    cout << (r - l + 1 - (pre[r] - pre[l - 1]) + mark[l] + (l != r ? mark[r] : 0)) << '\n'; 
  }
}



