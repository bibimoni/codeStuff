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
  vector<array<int, 3>> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i][0] >> a[i][1];
    a[i][2] = i + 1;
  }
  sort(a.begin(), a.end(), [&] (array<int, 3> i, array<int, 3> j) {
    return i[0] > j[0];
  });
  array<int, 3> last = a[0];
  vector<array<int, 3>> ans;
  for(auto [a, c, i] : a) {
    if(ans.size() && c > ans.back()[1])
      continue;
    ans.push_back({a, c, i});
  }
  sort(ans.begin(), ans.end(), [&] (array<int, 3> i, array<int, 3> j) {
    return i[2] < j[2];
  });
  cout << ans.size() << '\n';
  for(auto p : ans) {
    cout << p[2] << ' ';
  }
}


