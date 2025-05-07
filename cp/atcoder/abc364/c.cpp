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
  int n, x, y;
  cin >> n >> x >> y;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i].second;
  }
  auto getAns = [&] (vector<pair<int, int>> &arr) {
    int ret = 0, sw = 0, ss = 0;
    for (int i = 0; i < n; i++) {
      if (sw > x || ss > y) {
        break;
      }
      sw += arr[i].first;
      ss += arr[i].second;
      ret += 1;
    }
    return ret;
  };
  sort(a.begin(), a.end(), greater<pair<int, int>>());
  int ans1 = getAns(a);
  sort(a.begin(), a.end(), [&] (pair<int, int> &i, pair<int, int> &j) {
    return i.second > j.second;
  });
  int ans2 = getAns(a);
  cout << min(ans1, ans2) << '\n';
}


