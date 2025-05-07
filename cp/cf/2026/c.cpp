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
#define int int64_t 

const int INF = 1e18;
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    int ans = n * (n + 1) / 2;
    for (int i = n - 1; i >= 1; i--) { 
      if (s[i] == '1' && cnt < i) {
        ans -= i + 1;
        cnt += 1;
      } else {
        cnt -= 1;
        cnt = max(int(0), cnt);
      }
    }
    cout << ans << '\n';
  }
}


