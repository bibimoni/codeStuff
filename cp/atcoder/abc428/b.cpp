/**
 * Author: distiled
 */
#include <bits/stdc++.h>
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
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  map<string, int> mp;
  int mx = 0;
  for (int i = 0; i + k - 1 < n; i++) {
    string t = s.substr(i, k);
    mp[t] += 1;
    mx = max(mp[t], mx);
  }
  vector<string> ans;
  for (auto [t, cnt] : mp) {
    if (cnt == mx) {
      ans.push_back(t);
    }
  }

  sort(ans.begin(), ans.end());
  cout << mx << '\n';
  for (auto t : ans) {
    cout << t << ' ';
  }
}
