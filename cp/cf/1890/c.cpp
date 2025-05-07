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

bool check(string t) {
  for(int i = 1; i < t.size(); i++) {
    if(t[i] == t[t.size() - i]) {
      return false;
    }
  }
  return true;
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt; cin >> tt;
  while(tt--) {
    int n; cin >> n;
    string s; cin >> s;
    s = "#" + s;
    int cnt = 0;
    vector<int> ans;
    int i = 1;
    while(!check(s)) {
      if(cnt > 300) break;
      bool check = false;
      for(; i < s.size(); i++) {
        if(s[i] == s[s.size() - i]) {
          if(s[i] == '0') ans.push_back(s.size() - i);
          else ans.push_back(i - 1);
          check = true;
          break;
        }
      }
      if(check) {
        string t = "";
        for(int i = 0; i < s.size(); i++) {
          if(i != ans.back()) t += s[i];
          if(i == ans.back()) t += s[ans.back()], t += "01";
        }
        s = t;
        cnt++;
      }
      else break;
    }
    if(!check(s) || (n & 1)) {
      cout << "-1\n";
      continue;
    }
    cout << ans.size() << '\n';
    for(int i : ans) cout << i << ' '; cout << '\n';
    
  }
}


