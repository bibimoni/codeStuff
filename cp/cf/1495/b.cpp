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
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  auto get = [&] (auto f) -> pair<vector<int>, vector<pair<int, int>>> {
    vector<int> mark(n, 0);
    for (int i = 0; i < n; i++) {
      if (i == 0 && f(p[i], p[i + 1])) {
        mark[i] = 1;
      } else if (i == n - 1 && f(p[i], p[i - 1])) {
        mark[i] = 1;
      } else if (i > 0 && i + 1 < n && f(p[i], p[i + 1]) && f(p[i], p[i - 1])) {
        mark[i] = 1;
      }
    }    
    vector<pair<int, int>> go(n, {-1, -1});
    for (int i = 0; i < n; i++) {
      if (mark[i] == 0) {
        continue;
      }
      go[i] = {i, i};
      for (int j = i - 1; j >= 0; j--) {
        if (j == 0) {
          go[i].first = j;
        } else if (j > 0 && f(p[j - 1], p[j])) {
          go[i].first = j;
          break;
        }
      }
      for (int j = i + 1; j < n; j++) {
        if (j == n - 1) {
          go[i].second = j;
        } else if (j + 1 < n && f(p[j + 1], p[j])) {
          go[i].second = j;
          break;
        }
      }
    }
    return {mark, go};
  };
  
  auto [mx, gox] = get([&] (int i, int j) { return i > j; });
  auto [my, goy] = get([&] (int i, int j) { return i < j; });
  mx[0] = mx[n - 1] = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (mx[i] == 0) {
      continue;
    }
    bool ok = true;
    // go left
    {
      auto idx = gox[i].first;
      if (my[idx] == 1) {
        auto [l, r] = goy[idx];
        ok &= ((i - idx + 1) % 2 == 1 && (idx - l) < (i - idx)) || ((gox[i].second - i) > (i - idx) && (gox[i].second - i) > (idx - l));
      }
    }
    // go right
    {
      int idx = gox[i].second;
      if (my[idx] == 1) {
        auto [l, r] = goy[idx];
        ok &= ((idx - i + 1) % 2 == 1 && (r - idx) < (idx - i)) || ((i - gox[i].first) > (idx - i) && (i - gox[i].first) > (r - idx));
      }
    }
    ans += int(ok);
  }
  cout << ans << '\n';
}

