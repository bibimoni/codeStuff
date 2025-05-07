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
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (accumulate(a.begin(), a.end(), int(0)) <= m) {
    cout << "infinite";
    return 0;
  }
  int l = 0, r = int(1e18), ret = int(1e18);
  while (l <= r) {
    int mid = (l + r) >> 1;
    int cur = 0;
    for (int i : a) {
      cur += min(mid, i);
    }
    if (cur <= m) {
      l = mid + 1;
      ret = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << ret;
}


