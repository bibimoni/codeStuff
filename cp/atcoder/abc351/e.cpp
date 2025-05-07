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
  int n;
  cin >> n;
  vector<array<int, 2>> p(n);
  for(int i = 0; i < n; i++) {
    cin >> p[i][0] >> p[i][1];
  }
  array<vector<array<int, 2>>, 2> groups;
  for(int i = 0; i < n; i++) {
    groups[(p[i][0] + p[i][1]) % 2].push_back({p[i][0] + p[i][1], p[i][0] - p[i][1]});
  };
  int ans = 0;
  for(int k = 0; k < 2; k++) {
    vector<int> x, y;
    for(int i = 0; i < groups[k].size(); i++) {
      x.push_back(groups[k][i][0]);
    }
    for(int i = 0; i < groups[k].size(); i++) {
      y.push_back(groups[k][i][1]);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    for(int i = 0; i < x.size(); i++) {
      ans += (2 * i + 1 - x.size()) * x[i];
    }
    for(int i = 0; i < y.size(); i++) {
      ans += (2 * i + 1 - y.size()) * y[i];
    }
  }
  cout << ans / 2;
}


