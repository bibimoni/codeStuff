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

bool isC(char i) {
  return i == 'b' || i == 'c' || i == 'd';
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n; cin >> n;
    string s; cin >> s;
    string ans = "";
    string curr = "";
    for(int i = 0; i < n; i++) {
      if(isC(s[i])) {
        if(!curr.size()) {
          curr += s[i];
        }
        else if(curr.size() == 1) {
          ans += curr;
          ans += ".";
          curr = "";
        }
        else if(curr.size() == 2) {
          if(i < n - 1 && !isC(s[i + 1])) {
            ans += curr;
            ans += ".";
            curr = s[i];
          }
          else {
            curr += s[i];
          }
        }
        else if(curr.size() == 3) {
          ans += curr; ans += ".";
          curr = s[i];
        }
      }
      else {
        curr += s[i];
      }
    }
    ans += curr;
    cout << ans << '\n'; 
  }
}


