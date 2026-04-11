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

const int N = int(2e5 + 1);
vector<int> was(N);
const int QK = 120;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    vector<int> s;
    for (int i = 0; i < n; i++) {
      int k;
      cin >> k;
      for (int j = 0; j < k; j++) {
        int x;
        cin >> x;
        s.push_back(x);
        a[i].push_back(x);
      }
      sort(a[i].begin(), a[i].end());
    }

    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());

    for (auto &p : a) {
      for (int &x : p) {
        x = lower_bound(s.begin(), s.end(), x) - s.begin();
      }
    }

    int st1 = -1, st2 = -1;
    for (int i = 0; i < n; i++) {
      if (int(a[i].size()) < QK) {
        continue;
      }
      for (int x : a[i]) {
        was[x] = 1;
      }
      for (int j = 0; j < n; j++) {
        if (i == j) {
          continue;
        }
        int cnt = 0;
        for (int y : a[j]) {
          cnt += was[y];
        }
        if (cnt >= 2) {
          st1 = i;
          st2 = j;
        }
      }

      for (int x : a[i]) {
        was[x] = 0;
      }
    }

    vector<pair<pair<int, int>, int>> e;
    for (int i = 0; i < n; i++) {
      if (int(a[i].size()) >= QK) {
        continue;
      }
      for (int j = 0; j < int(a[i].size()); j++) {
        for (int k = j + 1; k < int(a[i].size()); k++) {
          e.push_back({{a[i][k], a[i][j]}, i});
        }
      }
    }

    sort(e.begin(), e.end());
    for (int i = 0; i + 1 < int(e.size()); i++) {
      if (e[i].first == e[i + 1].first) {
        st1 = e[i].second;
        st2 = e[i + 1].second;
      }
    }

    if (st1 == -1) {
      cout << "-1\n";
    } else {
      cout << st1 + 1 << ' ' << st2 + 1 << '\n';
    }
  }
}
