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
// #define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int N = 100;
  vector<pair<int, int>> a{{0, 0}, {1, 1}};
  for (int i = 2; i <= N; i++) {
    if (i % 2 == 0) {
      a.emplace_back(2 * a[i / 2].first, i);
    } else {
      a.emplace_back(a[i / 2].first - 3 * a[i / 2 + 1].first, i);
    }
  }
  for (auto [v, i] : a) {
    int sum = 0;
    for (int j = 0; j <= i; j++) {
      sum += a[j].first;
    }
    cout << i << ' ' << sum << '\n';
  }
}
