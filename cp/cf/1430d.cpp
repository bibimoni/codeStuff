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
#define all(x)         x.begin(), x.end()

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> group;
    s += " ";
    int curr = 1;
    for(int i = 1; i <= n; i++) {
      if(s[i] != s[i - 1]) {
        group.push_back(curr);
        curr = 1;
      }
      else {
        curr++;
      }
    }
    dbg(group);
    n = (int) group.size();
    int j = 0, ans = 0;
    for(int i = 0; i < n; i++) {
      while(j < n) {
        if(group[j] > 1) {
          group[j]--;
          break;
        }
        j++;
      }
      dbg(i, j, n);
      if(j == n) {
        ans += (n - i - 1) / 2 + 1;
        break;
      }
      while(j <= i) j++;
      ans++;
    }
    cout << ans << '\n';
  }
}
