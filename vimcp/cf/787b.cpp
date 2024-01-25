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
  int n, m; cin >> n >> m;
  vector<int> groups[m];
  for(int i = 0; i < m; i++) {
    int k; cin >> k;
    for(int j = 0; j < k; j++) {
      int x;
      cin >> x;
      groups[i].push_back(x);
    }
  }
  bool possible = false;
  for(auto group : groups) {
    if(possible) {
      break;
    }
    bool impossible = false;
    map<int, bool> f;
    for(int i : group) {
      if(f[-i]) {
        impossible = true;
        break;
      }
      f[i] = true;
    }
    if(!impossible) possible = true;
  }
  cout << (possible ? "YES\n" : "NO\n");
}

