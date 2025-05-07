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
    int n = s.size();
    for (int i = 1; i < n; i++) {
      if (s[i] == '0') {
        continue;
      }
      int ci = s[i] - '0';
      for (int j = max(int(0), i - ci + 1); j < i; j++) {
        int mi = i - j;
        int cj = s[j] - '0';
        if (cj < ci - mi) {
          for (int k = i; k > j; k--) {
            swap(s[k], s[k - 1]);
          }
          s[j] = char(ci - mi + '0');
          break;
        }
      }
    }
    cout << s << '\n';
  }
}


