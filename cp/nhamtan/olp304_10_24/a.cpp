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
#define int            long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  string s; 
  cin >> s;
  int n = s.size();
  s = " " + s;
  vector<array<int, 3>> cnt(n + 1, {{0, 0, 0}});
  for(int i = 1; i <= n; i++) {
    if(s[i] == 'O') {
      s[i] = '1';
    }
    if(s[i] == 'L') {
      s[i] = '2';
    }
    if(s[i] == 'P') {
      s[i] = '3';
    }
    for(int j = 0; j < 3; j++) {
      cnt[i][j] = cnt[i - 1][j] + (int)((s[i] - '1') == j);
    }
  }
  int ans = 0;
  for(int i = 1; i + 2 <= n; i++) {
    int l = i + 2, r = n, ret = -1;
    while(l <= r) {
      int mid = (l + r) >> 1;
      bool ok = false;
      for(int j = 0; j < 3; j++) {
        ok |= (cnt[mid][j] - cnt[i - 1][j] >= 3);
      }
      if(ok) {
        r = mid - 1;
        ret = mid;
      }
      else {
        l = mid + 1;
      }
    }
    if(ret != -1)
      ans += n - ret + 1;
  }
  cout << ans << '\n';
}


