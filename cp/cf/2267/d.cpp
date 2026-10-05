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
// #define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    array<vector<int>, 2> a {vector<int>{}, vector<int>{}};

    bool mx_odd = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x == n) {
        mx_odd |= (i & 1);
        continue;
      }
      if (i & 1) {
        a[1].push_back(x);
      } else {
        a[0].push_back(x);
      }
    }

    if (n == 1) {
      cout << "Yes\n";
      continue;
    }
    if (n == 2) {
      cout << "Yes\n";
      // cout << (a[0] < a[1] ? "Yes\n" : "No\n");
      continue;
    }

    array<int, 2>sz {{int(a[0].size()), int(a[1].size())}};
    sort(a[0].begin(), a[0].end());
    sort(a[1].begin(), a[1].end());

    vector<pair<int, int>> left{{n, mx_odd}},right{{n, mx_odd}};
    mx_odd ^= 1;
    dbg("hi", a)
    
    bool ok = true;
    while(n > 1) {
      if (a[mx_odd].size() == 0) {
        if (a[1 ^ mx_odd].size() == 0) {
          ok = false;
          break;
        }
        mx_odd ^= 1;
      }
      auto nxt = a[mx_odd].back();
      a[mx_odd].pop_back();
      auto [left_val, left_odd] = left.back();
      auto [right_val, right_odd] = right.back();
      if (left_val > nxt && ((left_odd ^ mx_odd) == 1)) {
        left.push_back({nxt, mx_odd});
      } else if (right_val > nxt && ((right_odd ^ mx_odd) == 1)) {
        right.push_back({nxt, mx_odd});
      } else {
        ok = false;
        break;
      }
      mx_odd ^= 1;
      n -= 1;
    }
    dbg(left, right, ok);

    cout << (ok ? "Yes\n" : "No\n");
  }
}
