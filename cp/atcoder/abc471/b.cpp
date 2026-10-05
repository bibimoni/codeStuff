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
// #define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  map<string, int> mp;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
        return std::tolower(c);
    });
    mp[s] += 1;
    ans = max(ans, mp[s]);
  }

  cout << ans << '\n'; 
}
