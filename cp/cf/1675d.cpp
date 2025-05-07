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
    vector<int> p(n + 1);
    vector<int> mark(n + 1, 0);
    for(int i = 1; i <= n; i++) {
      cin >> p[i];
      mark[p[i]] = 1;
    }
    vector<int> leaves;
    for(int i = 1; i <= n; i++) {
      if(!mark[i]) {
        leaves.push_back(i);
      }
    }
    if(n == 1) 
      leaves.push_back(1);
    mark = vector<int>(n + 1, 0);
    vector<vector<int>> ans;
    for(int u : leaves) {
      vector<int> curr;
      while(!mark[u]) {
        mark[u] = 1;
        curr.push_back(u);
        u = p[u];
      }
      reverse(curr.begin(), curr.end());
      ans.push_back(curr);
    }
    cout << ans.size() << '\n';
    for(auto p : ans) {
      cout << p.size() << '\n';
      for(int i : p) {
        cout << i << ' ';
      }
      cout << '\n';
    }
    cout << '\n';
  }
}

