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

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, r; cin >> n >> r;
  int a[n], m[n];
  for(int i = 0; i < n; i++) {
    cin >> a[i] >> m[i];
  }
  while(r--) {
    int u, v; cin >> u >> v;
    int time = 0, idx = 0;
    for(int i = 0; i < n; i++) {
      if(time < u * a[i] + v * m[i]) {
        time = u * a[i] + v * m[i];
        idx = i;
      }
    }
    cout << idx + 1 << "\n";
  }
}

