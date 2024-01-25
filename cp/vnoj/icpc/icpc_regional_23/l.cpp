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
    int m; cin >> m;
    string s; cin >> s;
    if(m == 1) {
      cout << "YES\n";
    }
    else if(m > s.size()) {
      cout << "NO\n";
    }
    else {
      bool ok = false;
      for(int i = 0; i < s.size() - m; i++) {
        if(s[i] == '1') {
          cout << "YES\n";
          ok = true;
          break;
        }
      }
      if(ok) continue;
      if(s[(int) s.size() - m] == '0') {
        cout << "NO\n";
        continue;
      }
      ok = false;
      for(int i = s.size() - m + 1; i < (int) s.size(); i++) {
        if(s[i] == '1') {
          ok = true;
          break;
        }
      }
      if(ok) {
        cout << "YES\n";
      }
      else {
        cout << "NO\n";
      }
    }
  }
}

