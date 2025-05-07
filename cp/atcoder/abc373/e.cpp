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
  int n, m, k;
  cin >> n >> m >> k;
  // cand i will be selected if and only if # of (cands with votes > vote[i]) < M
  // cand i received votes -> become the m-th or smaller position of the cands
  // the remaining votes must not affect the position (make the posistion > M)
  // the remaining votes go to the M + 1 cands
  // x_{i-1} x_i x_{i+1}
  // (x_i + k) >= (x_m + (rem_votes - k))
  vector<pair<int, int>> cands(n + 1);
  int rem_votes = k;
  for (int i = 1; i <= n; i++) {
    cin >> cands[i].first;
    cands[i].second = i;
    rem_votes -= cands[i].first;
  }
  sort(cands.begin() + 1, cands.end(), [&] (pair<int, int> i, pair<int, int> j) {
    return i.first < j.first;
  });
  vector<int> p(n + 1);
  for (int i = 1; i <= n; i++) {
    p[i] = p[i - 1] + cands[i].first;
  }
  auto find = [&] (int val) -> int {
    int lo = 1, hi = n, ret = n;
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      if (cands[mid].first >= val) {
        lo = mid + 1;
        ret = mid;
      } else {
        hi = mid - 1;
      }
    }
    return ret;
  };
  vector<int> ans(n + 1);
  for (int i = 1; i <= n; i++) {
    auto [a, id] = cands[i];
    int ret = -1, lo = 0, hi = rem_votes;
    dbg(a);
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      int idx = find(a + mid);
      int exceed = (a + mid + 1) * (idx - 1 - (n - m) + 1) - (p[idx] - p[n - m - 1] - a);
      dbg(mid, exceed, a + mid,  (a + mid + 1) * (idx - n + m), p[idx] - p[n - m - 1] - a);
      dbg(idx, (idx - 1 - (n - m) + 1), rem_votes - mid)
      if (idx >= n - m + 1 && exceed > rem_votes - mid) {
        hi = mid - 1;
        ret = mid;
      } else {
        lo = mid + 1;
      }
    }
    ans[id] = ret;
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " \n"[i == n];
  }
}

