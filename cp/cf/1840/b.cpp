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
    int n, k;
    cin >> n >> k;
    int ans = 0;
    vector<int> arr;
    for (int i = 0; i < k; i++) {
      if ((int(1) << i) <= n) {
        arr.push_back(int(1) << i);
      } else {
        break;
      }
    }
    map<pair<int, int>, int> memo;
    auto dfs = [&] (int cur, int i) {
      if (cur >= 0) {
        return 1;
      }
      
    };
  }
}

