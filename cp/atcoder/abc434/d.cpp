/**
 * Author: distiled
 */
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
// #define int int64_t

const int N = 2000;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector pre(N + 2, vector(N + 2, 0));
  vector<array<int, 4>> rec;
  for (int i = 0; i < n; i++) {
    int u, d, l, r;
    cin >> u >> d >> l >> r;
    rec.push_back({u, d, l, r});
    pre[u][l] += 1;
    pre[u][r + 1] -= 1;
    pre[d + 1][l] -= 1;
    pre[d + 1][r + 1] += 1;
  }

  vector<set<int>> xs(N + 2);
  set<int> x;
  int cnt0 = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
      if (pre[i][j] == 0) {
        cnt0 += 1;
      } else if (pre[i][j] == 1) {
        xs[i].insert(j);
        x.insert(i);
      }
    }
  }

  for (auto p : rec) {
    int x1 = p[0], x2 = p[1], y1 = p[2], y2 = p[3];
    dbg(p);
    auto it = x.lower_bound(x1);
    int ans = cnt0;

    vector<int> remx;
    for (auto it1 = it; it1 != x.end() && (*it1) <= x2; it1++) {
      int cx = *it1;
      auto ity = xs[cx].lower_bound(y1);
      vector<int> rem;
      for (auto it2 = ity; it2 != xs[cx].end() && (*it2) <= y2; it2++) {
        ans += 1;
        dbg(cx, *it2);
        rem.push_back(*it2);
      }
      for (int y : rem) {
        xs[cx].erase(y);
      }
      if (xs[cx].size() == 0) {
        remx.push_back(cx);
      }
    }

    for (int cx : remx) {
      x.erase(cx);
    }

    cout << ans << '\n';
  }
}
