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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int mhalf = n / 2 + 1;
    const int INF = (int) 1e18;
    int lo = 0, hi = INF, ans = INF;
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      vector<int> b = a;
      (*max_element(b.begin() + 1, b.end())) += mid;
      int cnt = 0;
      int sum = accumulate(b.begin() + 1, b.end(), 0ll);
      for (int i = 1; i <= n; i++) {
        cnt += sum > (b[i] * n * 2);
      }   
      if (cnt >= mhalf) {
        ans = mid;
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }
    cout << (ans == INF ? -1 : ans) << '\n';
  }
}


