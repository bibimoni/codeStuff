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
    int n, m;
    cin >> n >> m;
    set<int> b;
    for(int i = 0; i < m; i++) {
      int x;
      cin >> x;
      b.insert(x);
    }
    vector<int> ans;
    for(int i = n; i >= 1; i--) {
      if(b.find(i) == b.end()) {
        ans.push_back(i);
      }
    }
    for(int i : ans) {
      cout << i << ' ';
    }
    cout << '\n';
  }
}


