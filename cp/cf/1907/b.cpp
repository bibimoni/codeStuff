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

bool isLower(char i) {
  return tolower(i) == i;
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    string s; cin >> s;
    set<pair<int, char>> ansH;
    set<pair<int, char>> ansL;
    for(int i = 0; i < s.size(); i++) {
      if(s[i] == 'B') {
        if(ansH.size() && !isLower((*(ansH.rbegin())).second)) {
          ansH.erase(*ansH.rbegin());
        }
      }
      else if(s[i] == 'b') {
        if(ansL.size() && isLower((*(ansL.rbegin())).second)) {
          ansL.erase(*ansL.rbegin());
        }
      }   
      else {
        if(isLower(s[i])) ansL.insert({i, s[i]});
        else ansH.insert({i, s[i]});
      }
    }
    ansL.insert(ansH.begin(), ansH.end());
    for(auto [i, a] : ansL) cout << (char)a;
    cout << '\n';
  }
}


