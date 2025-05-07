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
    set<char> s;
    string str;
    cin >> str;
    int ans = 0;
    for(char c : str) {
      s.insert(c);
      ans += (int) s.size();
    }
    cout << ans << '\n';
  }
}


