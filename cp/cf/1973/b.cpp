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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<vector<int>> pre(n + 1, vector<int>(32, 0));
    for(int j = 30; j >= 0; j--) {
      for(int i = 1; i <= n; i++) {
        pre[i][j] = pre[i - 1][j] + ((a[i] >> j) & 1);
      }
    }
    auto can = [&] (int k) -> bool {
      int curr = 0;
      for(int j = 0; j < 30; j++) {
        if(pre[k][j] > 0)
          curr |= (1ll << j);
      }
      // dbg(k, curr);
      for(int i = k + 1; i <= n; i++) {
        int tmp = 0;
        for(int j = 0; j < 30; j++) {
          if(pre[i][j] - pre[i - k][j] > 0)
            tmp |= (1ll << j);
        }
        if(tmp != curr)
          return false;
      }
      return true;
    };
    int l = 1, r = n, ret = n;
    while(l <= r) {
      int mid = (l + r) >> 1;
      if(can(mid)) {
        r = mid - 1;
        ret = mid;
      }
      else {
        l = mid + 1;
      }
    }
    cout << ret << '\n';
  }
}


