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
    cin >> s;
    string tmp = s;
    reverse(tmp.begin(), tmp.end());
    if(tmp < s) {
      reverse(s.begin(), s.end());
      string t = s;
      reverse(t.begin(), t.end());
      s += t;
    }
    cout << s << '\n';
  }
}


