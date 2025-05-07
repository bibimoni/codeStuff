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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) {
      cin >> x;
    }
    int lo = 1, hi = *max_element(a.begin(), a.end()) + 1;
    int ret = 0;
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      int cnt = 0;
      set<int> cur;
      for (int x : a) {
        if (x < mid) {
          cur.insert(x);
        }
        if (cur.size() == mid) {
          cur.clear();
          cnt += 1;
        }
      }
      if (cnt >= k) {
        lo = mid + 1;
        ret = mid;
      } else {
        hi = mid - 1;
      }
    }
    cout << ret << '\n';
  }
}


