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
  vector<int> p(4);
  cin >> p[0] >> p[1] >> p[2] >> p[3];
  vector<int> cnt(5, 0);
  cnt[p[0]] += 1;
  cnt[p[1]] += 1;
  cnt[p[2]] += 1;
  cnt[p[3]] += 1;
  int ans = 0;
  for (int i = 1; i <= 4; i++) {
    ans += cnt[i] / 2;
  }
  cout << ans << '\n';
}


