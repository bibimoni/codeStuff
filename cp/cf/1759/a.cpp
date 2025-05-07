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
  string s;
  for(int i = 0; i < 28; i++) {
    s += "Yes";
  }
  int tt;
  cin >> tt;
  while(tt--) {
    string t; cin >> t;
    cout << (s.find(t) != string::npos ? "YES\n" : "NO\n");
  }
}


