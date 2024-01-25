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
    int n; cin >> n;
    string s; cin >> s;
    if(is_sorted(s.begin(), s.end())) {
      cout << "0\n";
      continue;
    }
    s = " " + s;
    char preM[n + 1]; preM[n] = s[n];
    for(int i = n - 1; i >= 1; i--) {
      preM[i] = max(preM[i + 1], s[i]);
    }
    string maxlexi = "", nonlexi = "";
    for(int i = 1; i <= n; i++) {
      if(preM[i] == s[i]) maxlexi += s[i];
      else nonlexi += s[i];
    }
    if(!is_sorted(nonlexi.begin(), nonlexi.end())) {
      cout << "-1\n";
      continue;
    }
    string t = ""; int idx = maxlexi.size() - 1;
    for(int i = 1; i <= n; i++) {
      if(s[i] != preM[i]) t += s[i];
      else t += maxlexi[idx--];
    }
    if(!is_sorted(t.begin(), t.end())) {
      cout << "-1\n";
      continue;
    }
    int ans = maxlexi.size();
    for(int i = 1; i < maxlexi.size(); i++) {
      if(maxlexi[i] == maxlexi[i - 1]) {
        ans--;
      }
      else {
        break;
      }
    }
    dbg(maxlexi, maxlexi.size());
    cout << ans - 1 << '\n';
  }
}


