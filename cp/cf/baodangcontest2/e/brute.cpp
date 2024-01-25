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
  int n; cin >> n;
  string s; cin >> s;
  int maxlen = 0;
  for(int len = 1; len <= n; len++) {
    map<string, int> f;
    for(int i = 0; i < n - len + 1; i++) {
      string sub = s.substr(i, len);
      bool ok = true;
      for(int j = 1; j < sub.size(); j++) {
        if(sub[j] != sub[j - 1]) ok = false;
      }
      if(!ok) continue;
      f[sub]++;
      if(f[sub] >= 2) {
        maxlen = max(maxlen, len);
      }
    }
  }
  if(maxlen > 0) cout << maxlen;
  else cout << "-1";
}

