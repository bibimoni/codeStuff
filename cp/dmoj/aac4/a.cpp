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
#define all(x)         x.begin(), x.end()

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m; cin >> n >> m;
  string s; cin >> s; 
  vector<pair<int, int>> a;
  for(int i = 0, x; i < m; i++) {
    cin >> x;
    a.push_back({x, i});
  }
  int cnt = 0, idx[n + 1];
  for(int i = 0; i < n; i++) {
    if(s[i] == '0') {
      idx[cnt++] = i;
    }
  }
  sort(all(a));
  string ans = "";
  auto [_, id] = a[m - 1];
  int b = idx[id];
  for(int i = b; i < n; i++) {
    if(s[i] != '0') ans += s[i];
  }
  for(int i = 0; i < b; i++)
    if(s[i] != '0') ans += s[i];
  cout << ans << '\n';
}


