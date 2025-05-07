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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> cnt(26);
    for(int i = 0; i < n; i++) {
      cnt[s[i] - 'A']++;
    }
    int ans = 0;
    for(char c = 'A'; c <= 'G'; c++) {
      if(cnt[c - 'A'] < m) {
        ans += m - cnt[c - 'A'];
      }
    }
    cout << ans << '\n';
  }
}


