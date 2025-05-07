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
  string s, t;
  cin >> s >> t;
  for(int i = 0, j = 0; i < t.size(); i++) {
    if(s[j] == t[i]) {
      j++;
      cout << i + 1 << ' ';
    }
  }
}


