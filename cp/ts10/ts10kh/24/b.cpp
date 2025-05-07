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
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = 0;
  for(char c : {'A', 'B'}) {
    string t = s;
    int currA = 0, currB = 0;
    for(int i = 0; i < n; i++) {
      if(t[i] == '*') {
        t[i] = c;
      }
    }
    for(int i = 0; i < n; i++) {
      if(i < n - 1) {
        currA += (t[i] == t[i + 1] && t[i] == 'A');
        currB += (t[i] == t[i + 1] && t[i] == 'B');
      }
    }
    ans = max({ans, currA, currB});
  }
  cout << ans << '\n';
}


