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
    vector<array<int, 2>> ans;
    for (int a = 1; a <= int(1e4); a++) {
      string s = to_string(n);
      int l = s.size();
      while (int(s.size()) < 8) {
        s += to_string(n);
      }
      for (int b = min(int(1e4), a * l); b >= max(1ll, a * l - 8); b--) {
        if (l * a - b > 0 && n * a - b == stoi(s.substr(0, l * a - b))) {
          ans.push_back({a, b});
        }
      }
    }
    cout << ans.size() << '\n';
    for (auto [a, b] : ans) {
      cout << a << ' ' << b << '\n';
    }
  }
}


