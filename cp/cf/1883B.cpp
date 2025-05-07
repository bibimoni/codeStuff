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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    map<char, int> f;
    for(char i : s) f[i]++;
    int need = 0;
    for(auto [_, cnt] : f) {
      if(cnt % 2 == 0) continue;
      need++;
    }
    if(need - k > 1) {
      cout << "NO\n";
    }
    else {
      cout << "YES\n";
    }
  }
}

