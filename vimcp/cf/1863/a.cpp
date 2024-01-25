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
    int n, a, q;
    cin >> n >> a >> q;
    string s; cin >> s;
    int m = 0, all = 0;
    bool maybe = false, ok = false;
    for(int i =0; i < q; i++) {
      if(a + m >= n) {
        ok = true;
      }
      if(s[i] == '-') m--;
      else m++, all++;
    }
    if(a + m >= n) ok = true;
    if(ok) {
      cout << "YES\n";
    }
    else if(a + all >= n) {
      cout << "MAYBE\n";
    }
    else {
      cout << "NO\n";
    }
  }
}


