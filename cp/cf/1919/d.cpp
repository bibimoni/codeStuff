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
    int n; cin >> n;
    int a[n + 2]; a[0] = -2, a[n + 1] = -2;
    int nxt[n + 1], prev[n + 1];
    vector<bool> mark(n + 1, false);
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
      nxt[i] = i + 1;
      prev[i] = i - 1;
    }
    auto ok = [&] (int i) {
      if(i < 1 || i > n) return false;
      return a[prev[i]] + 1 == a[i] || a[nxt[i]] + 1 == a[i];
    };
    priority_queue<pair<int, int>> q;
    for(int i = 1; i <= n; i++) {
      if(ok(i)) {
        mark[i] = true;
        q.push({a[i], i});
      }
    }
    while(!q.empty()) {
      auto [e, i] = q.top(); 
      q.pop();
      nxt[prev[i]] = nxt[i];
      prev[nxt[i]] = prev[i];
      if(!mark[prev[i]] && ok(prev[i])) {
        mark[prev[i]] = true;
        q.push({a[prev[i]], prev[i]});
      }
      if(!mark[nxt[i]] && ok(nxt[i])) {
        mark[nxt[i]] = true;
        q.push({a[nxt[i]], nxt[i]});
      }
    }
    int cnt = 0; bool check = false;
    for(int i = 1; i <= n; i++) {
      if(!mark[i] && a[i] == 0) check = true;
      cnt += (int)!mark[i];
    }
    if(cnt == 1 && check) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }
}


