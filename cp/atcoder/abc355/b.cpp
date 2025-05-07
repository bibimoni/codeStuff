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
#define int int64_t 

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> c;
  vector<int> pos(201, -1);
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    pos[x] = 1;
    c.push_back(x);
  } 
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    c.push_back(x);
  }
  sort(c.begin(), c.end());
  bool ok = false;
  for (int i = 1; i < int(c.size()); i++) {
    ok |= (pos[c[i]] + pos[c[i - 1]]) == 2;
  }
  cout << (ok ? "Yes\n" : "No\n");
}


