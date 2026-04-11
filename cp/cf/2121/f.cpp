/**
 * Author: distiled
 */
#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
#define int int64_t
const int LG = 20;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, s, x;
    cin >> n >> s >> x;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }

    int cur_sum = 0;
    int ans = 0;
    map<int, vector<int>> ss;
    ss[0].push_back(0);
    int last = -1;
    int first = -1;

    for (int i = 1; i <= n; i++) {
      cur_sum += a[i];
      if (a[i] > x) {
        last = -1;
        first = -1;
      } else if (a[i] == x) {
        if (last == -1) {
          last = i;
        }
        first = i;
      } else {
        if (last == -1) {
          last = i;
        }
      }
      int ll = last, rr = first;
      if (ll == -1 || rr == -1) {
        ss[cur_sum].push_back(i);
        continue;
      }
      int t = cur_sum - s;
      int lo = 0, hi = ss[t].size() - 1;
      int rt = -1;
      while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (ss[t][mid] > rr - 1) {
          hi = mid - 1;
        } else {
          lo = mid + 1;
          rt = mid;
        }
      }
      if (rt == -1) {
        ss[cur_sum].push_back(i);
        continue;
      }
      lo = 0, hi = ss[t].size() - 1;
      int lt = -1;
      while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (ss[t][mid] < ll - 1) {
          lo = mid + 1;
        } else {
          hi = mid - 1;
          lt = mid;
        }
      }

      if (lt == -1) {
        ss[cur_sum].push_back(i);
        continue;
      }
      ans += rt - lt + 1;
      ss[cur_sum].push_back(i);
    }
    cout << ans << '\n';
  }
}
