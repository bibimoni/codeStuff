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

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> x(n), y(m);
    vector<int> idx(n * m + 1);
    vector<int> idy(n * m + 1);
    set<int> xs, ys;
    for (int i = 0; i < n; i++) {
      cin >> x[i];
      xs.insert(x[i]);
      idx[x[i]] = i;
    }
    for (int i = 0; i < m; i++) {
      cin >> y[i];
      ys.insert(y[i]);
      idy[y[i]] = i;
    }

    set<int> a{x.begin(), x.end()};
    set<int> b{y.begin(), y.end()};

    if (a.size() != x.size()) {
      cout << "No\n";
      continue;
    }
    if (b.size() != y.size()) {
      cout << "No\n";
      continue;
    }

    vector<set<pair<int, int>>> sx(n * m + 1);
    vector<set<pair<int, int>>> sy(n * m + 1);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        sx[x[i]].insert({y[j], j});
        sy[y[j]].insert({x[i], i});
      }
    }

    // dbg(x, y);
    vector<vector<int>> ans(n, vector<int>(m, -1));
    bool ok = true;
    for (int v = n * m; v >= 1; v--) {
      bool ina = a.find(v) != a.end();
      bool inb = b.find(v) != b.end();
      // dbg(v, ina, inb, ok);
      int xp = -1, yp = -1;
      if (ina && inb) {
        xp = idx[v];
        yp = idy[v];
      } else if (ina && !inb) {
        if (sx[v].size() == 0) {
          ok = false;
          break;
        }
        auto it = sx[v].rbegin();
        auto [val, j] = *it;
        if (val < v) {
          ok = false;
          break;
        }
        xp = idx[v];
        yp = j;
      } else if (!ina && inb) {
        if (sy[v].empty()) {
          ok = false;
          break;
        }
        auto it = sy[v].rbegin();
        auto [val, i] = *it;
        if (val < v) {
          ok = false;
          break;
        }
        xp = i;
        yp = idy[v];
      } else {
        auto find = [&](set<int> &st, vector<set<pair<int, int>>> &s,
                        bool isx) -> pair<int, int> {
          if (st.size() == 0) {
            return {-1, -1};
          }
          auto it = st.rbegin();
          auto val = *it;
          if (val < v) {
            return {-1, -1};
          }
          if (s[val].size() == 0) {
            return {-1, -1};
          }
          auto it1 = s[val].rbegin();
          auto [vl, j] = *it1;
          if (vl < v) {
            return {-1, -1};
          }
          if (isx) {
            return {idx[val], j};
          }
          return {j, idy[val]};
        };
        auto [cx, cy] = find(xs, sx, true);
        if (cx != -1 && cy != -1) {
          xp = cx;
          yp = cy;
        } else {
          auto [dx, dy] = find(ys, sy, false);
          if (dx == -1 && dy == -1) {
            ok = false;
            break;
          }
          xp = dx;
          yp = dy;
        }
      }
      if (ans[xp][yp] != -1) {
        ok = false;
        break;
      }
      // dbg(xp, yp);
      ans[xp][yp] = v;
      sx[x[xp]].erase({y[yp], yp});
      sy[y[yp]].erase({x[xp], xp});
      if (sx[x[xp]].size() == 0) {
        xs.erase(x[xp]);
      }
    }

    dbg(ok, x, y, ans);
    if (ok) {
      for (int i = 0; i < n; i++) {
        int mx = 0;
        for (int j = 0; j < m; j++) {
          mx = max(mx, ans[i][j]);
        }
        assert(mx == x[i]);
      }

      for (int j = 0; j < m; j++) {
        int mx = 0;
        for (int i = 0; i < n; i++) {
          mx = max(mx, ans[i][j]);
        }
        assert(mx == y[j]);
      }
      cout << "Yes\n";
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          cout << ans[i][j] << " \n"[j == m - 1];
        }
      }
    } else {
      cout << "No\n";
    }
  }
}
