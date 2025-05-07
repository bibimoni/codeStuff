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

const int N = (int) 3e5 + 5, INF = (int) 1e18;

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n; cin >> n;
    string s; cin >> s;
    s = " " + s;
    vector<int> leaf, l(n + 1), r(n + 1);
    for(int i = 1; i <= n; i++) {
      cin >> l[i] >> r[i];
      if(!l[i] && !r[i]) leaf.push_back(i);
    }
    vector<int> d(n + 1, 0);
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
      int u = q.front(); q.pop();
      dbg(d);
      char letter = s[u];
      int lu = l[u], ru = r[u];
      if(lu) {
        d[lu] = d[u] + (s[u] != 'L');
        q.push(lu);
      }
      if(ru) {
        d[ru] = d[u] + (s[u] != 'R');
        q.push(ru);
      }
    }
    int ans = INF; 
    for(auto i : leaf) {
      ans = min(ans, d[i]);
    }
    cout << ans << '\n';
  }
}


