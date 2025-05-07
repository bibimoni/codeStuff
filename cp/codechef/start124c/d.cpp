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
  int tt;
  cin >> tt;
  while(tt--) {
    string s;
    cin >> s;
    int n = s.size();
    int ans = n;
    for(char c = 'a'; c <= 'z'; c++) {
      vector<int> a(n);
      for(int i = 0; i < n; i++) {
        a[i] = (s[i] == c);
      }
      int sz = accumulate(a.begin(), a.end(), 0);
      if(sz == 0)
        continue;
      int curr = 0;
      for(int i = 0; i < sz; i++) {
        curr += a[i];
      }
      ans = min(ans, sz - curr);
      for(int i = sz; i < n; i++) {
        curr -= a[i - sz];
        curr += a[i];
        ans = min(ans, sz - curr);
      }
    }
    cout << ans << '\n';
  }
}


