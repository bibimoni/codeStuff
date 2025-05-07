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
  int m;
  cin >> m;
  vector<int> ans;
  while (m) {
    int t = 0;
    while (pow(int(3), t) <= m) {
      t += 1;
    }
    t -= 1;
    ans.push_back(t);
    m -= pow(int(3), t);
  }
  cout << ans.size() << '\n';
  for (int i : ans) {
    cout << i << ' ';
  }
}

