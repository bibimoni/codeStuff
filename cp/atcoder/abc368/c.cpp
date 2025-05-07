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
  vector<int> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int goto_3 = 3 - (ans % 3);
    if (h[i] <= goto_3 - 1 + 3) {
      for (int j = 0; h[i] > 0 && j < goto_3; j++) {
        h[i] -= (j < goto_3 - 1 ? 1 : 3);
        ans += 1;
      }      
      continue;
    } else {
      h[i] -= (goto_3 - 1) + 3;
      ans += goto_3;
    }
    int need = h[i] / 5;
    h[i] -= need * 5;
    ans += need * 3;
    dbg(ans, goto_3, i, h[i], need);
    if (h[i] <= 2) {
      ans += h[i];
      h[i] = 0;
    } else {
      ans += 3;
      h[i] = 0;
    }
  }
  cout << ans << '\n';
}


