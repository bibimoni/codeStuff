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
#define all(x)         x.begin(), x.end()

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt; cin >> tt;
  while(tt--) {
    int n; cin >> n;
    map<int, vector<int>> f;
    for(int x, i = 0; i < n; i++) {
      cin >> x;
      f[x].push_back(i);
    }
    vector<int> b(n, -1);
    int cnt = 0;
    for(auto [i, v] : f) {
      if(v.size() >= 2) {
        cnt++;
        b[v[0]] = 1;
        if(cnt == 1) b[v[1]] = 2;
        else b[v[1]] = 3;
      }
    }
    if(cnt < 2) {
      cout << -1 << '\n';
    }
    else {
      for(int i = 0; i < n; i++) {
        if(b[i] == -1) b[i] = 1;
      }
      for(int i : b) cout << i << ' ';
      cout << '\n';
    }
  }
}


