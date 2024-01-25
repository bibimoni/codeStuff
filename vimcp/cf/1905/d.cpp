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
    int p[n + 1]; 
    vector<int> t(n + 1, 0);
    deque<pair<int, int>> dq;
    int currMex = 0;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
      cin >> p[i];
    }
    for(int i = 1; i <= n; i++) {
      t[p[i]]++;
      while(t[currMex]) {
        currMex++;
      }
      dq.push_back({currMex, 1});
      ans += currMex;  
    }    
    vector<pair<int, int>> mex;
    int curr = ans;
    for(int i = 1; i < n; i++) {
      curr -= dq.front().first;
      dq.front().second--; 
      if(!dq.front().second) {
        dq.pop_front();
      }
      pair<int, int> add = {p[i], 0};
      while(dq.size() && dq.back().first > p[i]) {
        curr -= dq.back().first * dq.back().second;
        add.second += dq.back().second;
        dq.pop_back();
      }
      dq.push_back(add), dq.push_back({n, 1});
      curr += add.first * add.second + n;
      ans = max(ans, curr);
    }
    cout << ans << '\n';
  }
}


