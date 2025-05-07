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
  int n;
  cin >> n;
  vector<array<int, 3>> req(n + 1);
  map<pair<int, int>, int> reqId;
  for(int i = 1; i <= n; i++) {
    cin >> req[i][0] >> req[i][1];
    req[i][2] = i;
  }
  int k;
  cin >> k;
  vector<array<int, 2>> r(k + 1);
  for(int i = 1; i <= k; i++) {
    cin >> r[i][0];
    r[i][1] = i;
  }
  sort(req.begin() + 1, req.end(), [&] (array<int, 3> i, array<int, 3> j) {
    return i[1] > j[1];
  });
  sort(r.begin() + 1, r.end());
  vector<pair<int, int>> ans;
  vector<int> mark(k + 1, 0);
  int sum = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= k; j++) {
      if(req[i][0] <= r[j][0] && !mark[j]) {
        mark[j] = 1;
        ans.push_back({req[i][2], r[j][1]});
        sum += req[i][1];
        break;
      }
    }
  }
  cout << ans.size() << ' ' << sum << '\n';
  for(auto [i, j] : ans) {
    cout << i << ' ' << j << '\n';
  }
}

