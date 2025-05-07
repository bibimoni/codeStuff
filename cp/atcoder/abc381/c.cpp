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
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> sz_1(n);
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      sz_1[i] += (i == 0 ? 1 : sz_1[i - 1] + 1);
    } else {
      sz_1[i] = 0;
    }
  }
  vector<int> sz_2(n);
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '2') {
      sz_2[i] += (i == n - 1 ? 1 : sz_2[i + 1] + 1);
    } else {
      sz_2[i] = 0;
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '/') {
      if (i == 0 || i == n - 1) {
        ans = max(ans, int(1));
      } else {
        ans = max(ans, min(sz_1[i - 1], sz_2[i + 1]) * 2 + 1);
      }
    }
  }
  cout << ans << '\n';
}


