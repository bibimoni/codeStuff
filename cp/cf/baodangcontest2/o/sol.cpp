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
#define int long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    bool ok = false;
    set<int> s({0});
    int curr = 0;
    for(int i = 1; i <= n; i++) {
      int x; 
      cin >> x;
      curr += x;
      if(s.find(curr - 2024) != s.end()) {
        ok = true;
      }
      s.insert(curr);
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}

