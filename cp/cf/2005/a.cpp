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
    string bruh = "aiueo";
    map<char, int> cnt;
    for (int i = 0; i < n; i++) {
      cnt[bruh[i % 5]] += 1;
    }
    string ans = "";
    for (auto [c, k] : cnt) {
      ans += string(k, c);
    }
    cout << ans << '\n';
  }
}


