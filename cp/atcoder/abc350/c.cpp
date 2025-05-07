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
#define int            long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  vector<int> pos(n + 1);
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    pos[a[i]] = i;
  }
  // 5 3 2 1 4
  vector<pair<int, int>> ans;
  for(int i = 1; i <= n - 1; i++) {
    if(pos[i] == i)
      continue;
    ans.push_back({i, pos[i]});
    pos[a[i]] = pos[i];
    a[pos[i]] = a[i];
    a[i] = i;
    pos[i] = i;
  }
  cout << ans.size() << '\n';
  for(auto [f, s] : ans)
    cout << f << ' ' << s << '\n';
}


