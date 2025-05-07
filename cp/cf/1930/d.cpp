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
    int n;
    cin >> n;
    string s;
    s = " " + s;
    vector<int> mark(n + 1, 0);
    vector<int> pref(n + 2, 0);
    for(int i = 1; i <= n; i++) {
      pref[i] = pref[i - 1] + (s[i] == '1');
    }
    int ans = 0;
    for(int l = 1; l <= n; l++) {
      for(int r = l; r <= n; r++) {
        
      }
    }
  }
}


