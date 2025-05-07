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
  int tt;
  cin >> tt;
  while (tt--) {
    int n, q;
    cin >> n >> q;
    map<int, int> idx;
    int len = 0;
    vector<pair<int, int>> dist;
    int curr = 0;
    for (int i = 0; i < n; i++) {
      int t, x;
      cin >> t >> x;
      if (len > int(1e18)) {
        continue;
      }
      if (t == 1) {
        len += 1; 
        idx[len] = x;
        curr = len;
        dist.push_back({len, curr});
      } else {
        if (len > int(2e18) / x) {
          len = int(2e18);
        } else {
          len += (len * x);
        }
        dist.push_back({len, curr});
      }
    }
    auto bs = [&] (int val) -> int {
      int l = 0, r = dist.size() - 1, ret = -1;
      while (l <= r) {
        int m = (l + r) >> 1;
        if (dist[m].first >= val) {
          ret = dist[m].second;
          r = m - 1;
        } else {
          l = m + 1;
        }
      }
      int id = val % ret == 0 ? ret : val % ret;
      return id;
    };
    while (q--) {
      int k;
      cin >> k;
      int id = k;
      while (!idx.count(id)) {
        id = bs(id);
      }      
      assert(id != -1 && idx.count(id));
      int num = idx[id];
      cout << num << " \n"[q == 0];
    }
  }
}


