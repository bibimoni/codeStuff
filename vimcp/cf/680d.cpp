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

int cb(int num) {
  return num * num * num;
}
vector<pair<int, int>> res;

void rec(int m, int curr, int total) {
  if(m == 0) {
    res.push_back({curr, total});
    return;
  }
  int a = 1; while(cb(a + 1) <= m) a++;
  rec(m - cb(a), curr + 1, total + cb(a));
  rec(cb(a) - 1 - (cb(a - 1)), curr + 1, total + cb((a - 1)));
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int m; cin >> m;
  rec(m, 0, 0);
  sort(all(res), greater<pair<int, int>>());
  cout << res[0].first << ' ' << res[0].second;
}


