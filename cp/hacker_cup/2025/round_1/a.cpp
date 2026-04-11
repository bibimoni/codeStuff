/**
 * Author: distiled
 */
#include <algorithm>
#include <bits/stdc++.h>
#include <memory>
#include <numeric>
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
  freopen("snake_scales_chapter_2_input.txt", "r", stdin);
  freopen("snake_scales_chapter_2_output.txt", "w", stdout);
  int tt;
  cin >> tt;
  for (int t = 1; t <= tt; t++) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    dbg(a);

    int lo = 0, hi = 1e18, ret = 1e18;
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      vector<int> was(n, 0);
      vector<int> cands;
      dbg(mid);
      for (int i = 0; i < n; i++) {
        if (a[i] <= mid) {
          cands.push_back(i);
        }
      }
      dbg(cands);
      for (auto i : cands) {
        was[i] = 1;
        dbg(i, was);
        for (int j = i; j > 0; j--) {
          dbg(a[j - 1], a[j], j, was[j - 1]);
          if (was[j - 1]) {
            break;
          }
          if (abs(a[j - 1] - a[j]) <= mid) {
            was[j - 1] = 1;
            dbg("HERE", was[j - 1], j - 1);
          } else {
            break;
          }
        }
        for (int j = i; j < n - 1; j++) {
          if (was[j + 1]) {
            break;
          }
          if (abs(a[j + 1] - a[j]) <= mid) {
            was[j + 1] = 1;
          } else {
            break;
          }
        }
      }
      dbg(was);
      int sum = accumulate(was.begin(), was.end(), int(0));
      if (sum == n) {
        hi = mid - 1;
        ret = mid;
      } else {
        lo = mid + 1;
      }
    }
    cout << "Case #" << t << ": " << ret << '\n';
  }
}
