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
  string s;
  cin >> s;
  map<char, int> f;
  for (char c : s) {
    f[c]++;
  }
  string t1 = "";
  string t2 = "";
  string rem = "";
  for (auto [c, cnt] : f) {
    if (cnt > 1) {
      while (cnt > 1) {
        t1 += c;
        t2 += c;
        cnt -= 2;
      }
    }
    if (cnt) {
      rem += c;
    }
  }
  reverse(t2.begin(), t2.end());
  if (!rem.size()) {
    cout << t1 + t2 << '\n';
  } else {
    string ans = t1 + rem[0] + t2 + rem.substr(1);
    for (int i = 1; i < rem.size(); i++) {
      string m1 = rem.substr(0, i);
      string m2 = ""; 
      if (i + 1 < rem.size()) {
        m2 = rem.substr(i + 1);
      }
      string tmp = m1 + t1 + rem[i] + t2 + m2;
      ans = min(ans, tmp);
    }
    cout << ans << '\n';
  }
}


