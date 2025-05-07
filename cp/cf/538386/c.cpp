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
    int n, m, v;
    cin >> n >> m >> v;
    vector<int> a(n + 1);
    vector<int> p(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      p[i] = p[i - 1] + a[i];
    }
    vector<int> nxt(n + 2, 0);
    for (int i = n; i >= 1; i--) {
      int l = i, r = n, ret = 0;
      while (l <= r) {
        int mid = (l + r) >> 1;
        if (p[mid] - p[i - 1] >= v) {
          r = mid - 1;
          ret = max(ret, nxt[mid + 1] + 1);
        } else {
          l = mid + 1;
        }
      }
      nxt[i] = ret;
    }
    vector<int> pre(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      int l = 1, r = i, ret = 0;
      while (l <= r) {
        int mid = (l + r) >> 1;
        if (p[i] - p[mid - 1] >= v) {
          l = mid + 1;
          ret = max(ret, pre[mid - 1] + 1);
        } else {
          r = mid - 1;
        }
      }
      pre[i] = ret; 
    }
    int ans = -1;
    for (int i = 1; i <= n; i++) {
      int l = i, r = n;
      if (nxt[i + 1] + pre[i] >= m) {
        ans = max(ans, int(0));
      }
      while (l <= r) {
        int mid = (l + r) >> 1;
        if (nxt[mid + 1] + pre[i - 1] >= m) {
          ans = max(ans, p[mid] - p[i - 1]);
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      } 
    }
    cout << ans << '\n';
  }
}


