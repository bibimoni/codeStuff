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
    int n; cin >> n;
    string s; cin >> s;
    int start = -1, end = -1;
    for(int i = 0; i < n; i++) {
      if(s[i] == 'B') {
        if(start == -1) start = i;
        end = max(i, start);
      }
    }
    if(start != -1 && end != -1) cout << end - start + 1 << '\n';
    else cout << "0\n";
  }
}


