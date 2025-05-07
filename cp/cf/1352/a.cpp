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
    vector<string> ans;
    string zero = "";
    for(int i = s.size() - 1; i >= 0; i--) {
      if(s[i] != '0') {
        ans.push_back(s[i] + zero);
      }
      zero += "0";
    }
    cout << ans.size() << '\n';
    for(string i : ans) {
      cout << i << ' ';
    }
    cout << '\n';
  }
}


