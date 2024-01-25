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
  int tt;
  cin >> tt;
  while(tt--) {
    int n; cin >> n;
    string s; cin >> s;
    int cnt = 0, ans = 0;
    for(int i = n - 1; i >= 0; i--) {
      if(s[i] == 'B') {
        cnt++;
        continue;
      }
      ans += cnt;
      if(!cnt) continue;
      s[i++] = 'B';
      cnt = 0;
    }
    cout << ans << '\n';
  }
}

