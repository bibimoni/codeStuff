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
  int tt;
  cin >> tt;
  while(tt--) {
    int x, n;
    cin >> n >> x;
    vector<int> p(n + 1), pos(n + 1);
    for(int i = 1; i <= n; i++) {
      cin >> p[i];
      pos[p[i]] = i;
    }
    int l = 1, r = n + 1;
    while(r - l > 1) {
      int m = (r + l) >> 1;
      if(p[m] <= x) {
        l = m;
      }
      else {
        r = m;
      }
    } 
    cout << "1\n" << l << ' ' << pos[x] << '\n';
  }
}

