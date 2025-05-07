// time-limit: 3000
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
#define all(x)         x.begin(), x.end()

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt; cin >> tt; 
  while(tt--) {
    int n, c; cin >> n >> c;
    int a[n + 1], p[n + 1];
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    iota(p + 1, p + n + 1, 1);
    sort(p + 1, p + n + 1, [&] (int u, int v) {
      return u * c - a[u] < v * c - a[v];
    });
    int curr = a[1]; bool check = true;
    for(int i = 1; i <= n; i++) {
      if(p[i] == 1) continue;
      if(curr + a[p[i]] < p[i] * c) {
        check = false;
        break;
      }
      curr += a[p[i]]; 
    }
    cout << (check ? "YES\n" : "NO\n");
  }
}


