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

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      pre[i] = pre[i - 1]  + a[i];
    }
    string s;
    cin >> s;
    s = " " + s;
    vector<int> lastR;
    for (int i = 1; i <= n; i++) {
      if (s[i] == 'R') {
        lastR.push_back(i);
      }
    }
    int ans = 0;
    for (int i = 1; int(lastR.size()) > 0 && i <= n; i++) {
      if (s[i] == 'L') {
        int r = lastR.back();
        if(r >= i) {
          lastR.pop_back();
          ans += pre[r] - pre[i - 1];
        }
      }
    }
    cout << ans << '\n';
  }
}


