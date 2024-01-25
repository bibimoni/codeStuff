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
    string s; cin >> s;
    int n = s.size();
    vector<int> pre1(n + 1, 0), pre0(n + 1, 0);
    s = "#" + s;
    for(int i = 1; i <= n; i++) {
      pre1[i] = pre1[i - 1] + (s[i] == '1');
      pre0[i] = pre0[i - 1] + (s[i] == '0');
    }
    int cnt1 = pre1[n], cnt0 = pre0[n];
    int ans = 0;
    for(int i = n; i >= 1; i--) {
      if(pre1[i] <= cnt0 && pre0[i] <= cnt1) {
        break;
      }
      ans++;
    }
    cout << ans << '\n';
  }
}


