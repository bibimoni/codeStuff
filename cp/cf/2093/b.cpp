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
    string s;
    cin >> s;
    int idx = -1;
    int cnt = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
      if (idx == -1 && s[i] != '0') {
        idx = i;
      } else if (idx != -1) {
        cnt += s[i] != '0';
      }
    }
    cout << s.size() - idx - 1 + cnt << '\n';
  }
}


