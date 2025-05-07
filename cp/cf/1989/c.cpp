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
#define int long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
    }
    int sc1 = 0, sc2 = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] == b[i] && a[i] == 1) {
        continue;
      }
      if (a[i] == 1) {
        sc1 += 1;
      }
      if (b[i] == 1) {
        sc2 += 1;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (a[i] == b[i] && a[i] == 1) {
        if (sc1 > sc2) {
          sc2 += 1;
        } else {
          sc1 += 1;
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      if (a[i] == b[i] && a[i] == -1) {
        if (sc1 > sc2) {
          sc1 -= 1;
        } else {
          sc2 -= 1;
        }
      }
    }
    cout << min(sc1, sc2) << '\n';
  }
}



