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
#define int long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    auto toNum = [&](string s) -> int {
      int ret = 0;
      for (int i = 0; i < s.size(); i++) {
        ret = (s[i] - '0') + ret * 10;
      }
      return ret;
    };
    if (n < 3) {
      cout << toNum(s) << '\n';
      continue;
    }
    bool hasZero = false;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0' && (i > 2 || n - i > 2)) {
        hasZero = true;
      }
    }
    if (hasZero) {
      cout << "0\n";
      continue;
    }
    int ans = 1e9;
    for (int pos = 0; pos < n - 1; pos++) {
      int curr = toNum(s.substr(pos, 2));
      for (int i = pos - 1; i >= 0; i--) {
        if (s[i] == '1')
          continue;
        curr = min(curr * toNum(s.substr(i, 1)), curr + toNum(s.substr(i ,1)));
      }
      for (int i = pos + 2; i < n; i++) {
        if (s[i] == '1')
          continue;
        curr = min(curr * toNum(s.substr(i, 1)), curr + toNum(s.substr(i ,1)));
      }
      ans = min(curr, ans);
    }
    cout << ans << '\n';
  }
}


