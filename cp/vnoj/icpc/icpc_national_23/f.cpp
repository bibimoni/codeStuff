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
    s = "#" + s;
    vector<int> cnt1(n + 1, 0), cnt2(n + 1, 0), cnt3(n + 1, 0);
    for(int i = 1; i <= n; i++) {
      cnt1[i] = cnt1[i - 1] + (s[i] == 'R');
      cnt2[i] = cnt2[i - 1] + (s[i] == 'S');
      cnt3[i] = cnt3[i - 1] + (s[i] == 'P');
    }
    int maxWins = 0, ans = 0;
    for(int k = 2; k <= n; k++) {
      int curr = 0;
      for(int i = k; i <= n; i += k) {
        curr += max({cnt1[i] - cnt1[i - k], cnt2[i] - cnt2[i - k], cnt3[i] - cnt3[i - k]});
        //dbg(i, k);
        //dbg(curr, cnt1[i] - cnt1[i - k], cnt2[i] - cnt2[i - k], cnt3[i] - cnt3[i - k]);
        if(i < n && i + k > n) {
          curr += max({cnt1[n] - cnt1[i], cnt2[n] - cnt2[i], cnt3[n] - cnt3[i]});
          //dbg("EXCEED", curr, cnt1[n] - cnt1[i], cnt2[n] - cnt2[i], cnt3[n] - cnt3[i]);
          break;
        }
      }
      // dbg(curr);
      if(maxWins <= curr) {
        maxWins = curr;
        ans = k;
      }
    }
    cout << ans << '\n';
  }
}

