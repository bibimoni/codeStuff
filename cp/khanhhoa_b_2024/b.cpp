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
  freopen("SODEP.inp", "r", stdin);
  freopen("SODEP.out", "w", stdout);
  int k;
  cin >> k;
  int cur = 1;
  int len = 1;
  while (cur * 2 < k) {
    cur *= 2;
    len += 1;
    k -= cur;
  }
  vector<int> ans(len, 5);
  k -= 1;
  int id = 0;
  while (k) {
    ans[id] = ((k % 2 == 0 ? 5 : 8));
    id += 1;
    k /= 2;
  }
  for (int i = ans.size() - 1; i >= 0; i--) {
    cout << ans[i];
  }
}


