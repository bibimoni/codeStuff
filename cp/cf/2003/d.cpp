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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1);
    vector<int> l(n + 1);
    vector<pair<int, int>> mex;
    for (int i = 1; i <= n; i++) {
      cin >> l[i];
      a[i].resize(l[i] + 1);
      for (int j = 1; j <= l[i]; j++) {
        cin >> a[i][j];
      }
      sort(a[i].begin() + 1, a[i].end());
    }
    auto find_mex = [&] (int len, vector<int> arr) -> int {
      int cur = 0;
      set<int> st(arr.begin() + 1, arr.end());
      for (int num : st) {
        if (num == cur) {
          cur += 1;
        } else {
          break;
        }
      }
      return cur;
    };
    for (int i = 1; i <= n; i++) {
      int mex_1 = find_mex(l[i], a[i]);
      auto tmp = a[i];
      tmp.push_back(mex_1);
      sort(tmp.begin() + 1, tmp.end());
      int mex_2 = find_mex(l[i] + 1, tmp);
    }
    sort(mex.begin(), mex.end());
    int ans = 0;
    cout << ans << '\n';
  }
}


