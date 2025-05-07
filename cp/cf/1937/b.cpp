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
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    string ans = "";
    bool down = false;
    int cs[n], ct[n];
    for(int i = n - 1; i >= 0; i--) {
      oks[i] = okt[i] = false;
      cs[i] = ct[i] = n;
      if(i == n - 1) {
        ct[i] = (t[i] == '1' ? n + 1 : n);
        if(ct[i] == n) {
          cs[i] = n;
        }
        cs[i] = (s[i] == '1' ? n + 1 : n - 1);
      }
      else {
        cs[i] = (s[i] == '0' ? i : cs[i + 1]);
        ct[i] = (t[i] == '0' ? i + 1 : ct[i + 1]);        
      }
    }
    for(int i = 0; i < n; i++) {
      if(!down && cs[i + 1] > ct[i] && i < n - 1) {
        down = true;
        ans += s[i];
      }
      if(down) {
        ans += t[i];
      }
      else {
        ans += s[i];
      }
    }
    if(!down) {
      ans += t[n - 1];
    }
    for(int i = 0; i < n; i++) {
      if(s[i] == ans[i]) {
        oks[i] = true;
      }
      else {
        break;
      }
    }
    for(int i = n - 1; i >= 0; i--) {
      if(t[i] == ans[i + 1]) {
        okt[i] = true;
      }
      else {
        break;
      }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) {
      cnt += (oks[i] && okt[i]);
    }
    cout << ans << '\n' << cnt << '\n';
  }
}