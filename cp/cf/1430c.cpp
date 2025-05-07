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
    priority_queue<int> q;
    for(int i = 1; i <= n; i++) q.push(i);
    vector<pair<int, int>> ans;
    while((int) q.size() > 1) {
      int f = q.top(); q.pop();
      int s = q.top(); q.pop();
      q.push((f + s - 1) / 2 + 1);
      ans.push_back({f, s});
    }
    cout << q.top() << '\n';
    for(auto [f, s] : ans) {
      cout << f << ' ' << s << '\n';
    }
  }
}


