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
  int n;
  cin >> n;
  string s;
  cin >> s;
  s = " " + s;
  vector<int> ans(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    ans[i] = ans[i - 1] + (s[i] - '0') * i;
  }  
  for (int i = n; i >= 1; i--) {
    ans[i - 1] += ans[i] / 10;
    ans[i] %= 10;
  }
  for (int i = (ans[0] != 0 ? 0 : 1); i <= n; i++) {
    cout << ans[i];
  }
}


