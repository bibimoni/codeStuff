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

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    vector<pair<int, int>> ops;
    auto goSwap = [&](vector<int> &a1, vector<int> &a2, int c, int id,
                      int val) -> void {
      if (a1[id] == val) {
        return;
      }
      for (int i = 0; i < n; i++) {
        if (a1[i] == val) {
          if (i > id) {
            for (int j = i; j > id; j--) {
              ops.push_back({c, j - 1});
              swap(a1[j - 1], a1[j]);
            }
          } else if (i < id) {
            for (int j = i; j < id; j++) {
              ops.push_back({c, j});
              swap(a1[j], a1[j + 1]);
            }
          }
          break;
        }
        if (a2[i] == val) {
          if (i > id) {
            for (int j = i; j > id; j--) {
              ops.push_back({c ^ 1, j - 1});
              swap(a2[j - 1], a2[j]);
            }
          } else if (i < id) {
            for (int j = i; j < id; j++) {
              ops.push_back({c ^ 1, j});
              swap(a2[j], a2[j + 1]);
            }
          }
          ops.push_back({2, id});
          swap(a1[id], a2[id]);
          break;
        }
      }
    };
    for (int i = 0; i < n; i++) {
      goSwap(a, b, 0, i, i + 1);
      dbg(a, b);
    }
    for (int i = 0; i < n; i++) {
      goSwap(b, a, 1, i, n + 1 + i);
      dbg(a, b);
    }
    cout << ops.size() << '\n';
    for (auto [u, v] : ops) {
      cout << u + 1 << ' ' << v + 1 << '\n';
    }
  }
}
