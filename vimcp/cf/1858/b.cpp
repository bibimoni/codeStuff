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
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m, d; cin >> n >> m >> d;
    int s[m + 2]; s[0] = 1 - d, s[m + 1] = n + 1;
    for(int i = 1; i <= m; i++) cin >> s[i];
    int total = 0;
    for(int i = 0; i <= m; i++) {
      total += (s[i + 1] - s[i] - 1) / d;
    }
    total += m;
    int cnt = 0;
    int ans = (int) 2e9;
    for(int i = 1; i <= m; i++) {
      int removal = (s[i + 1] - s[i - 1] - 1) / d - ((s[i + 1] - s[i] - 1) / d + (s[i] - s[i - 1] - 1) / d);
      if(removal < ans) {
        cnt = 1;
        ans = removal;
      }
      else if(removal == ans) {
        cnt++;
      }
    }
    cout << total + ans - 1 << ' ' << cnt << '\n';
  }
}

