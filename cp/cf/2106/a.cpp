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
    string s;
    cin >> s;
    int ans = 0;
    int sum = 0;
    for (char c : s) {
      sum += c == '1';
    }
    dbg(sum);
    for (char c : s) {
      ans += sum + (c == '1' ? -1 : 1);
    }
    cout << ans << '\n';
  }
}


