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
  for(int i = 0; i < t.size() - 1; i ++) {
    if(t[i] == t[i + 1])  return false;
  }
  return true;
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt; cin >> tt;
  while(tt--) {
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    if(check(s)) {
      cout<< "Yes\n";
      continue;
    }
    if(!check(t)) {
      cout << "No\n";
      continue;
    }

    bool check = true;
    for(int i = 0; i < s.size() - 1; i++) {
      if(s[i] == s[i + 1]) {
        if(!(s[i] != t[0] && s[i + 1] != t[m - 1])) {
          check = false;
          break;
        }
      }
    }
    cout << (check ? "Yes\n" : "No\n");
  }
}


