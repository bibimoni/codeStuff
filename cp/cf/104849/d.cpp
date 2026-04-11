/*k
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
  int h, w;
  cin >> h >> w;
  vector<pair<int, int>> a;
  for (int i = 0; i < h; i++) {
    string tmp;
    cin >> tmp;
    for (int j = 0; j < w; j++) {
      if (tmp[j] == 'o') {
        a.push_back({i, j});
      }
    }
  }
  vector<vector<pair<int, int>>> b(4);

  auto rot = [&](int x, int y, int opt) -> pair<int, int> {
    if (opt == 0) {
      return {x, y};
    } else if (opt == 1) {
      return {y, -x};
    } else if (opt == 2) {
      return {-x, -y};
    }
    return {-y, x};
  };
  int h1, w1;
  cin >> h1 >> w1;
  for (int i = 0; i < h1; i++) {
    string tmp;
    cin >> tmp;
    for (int j = 0; j < w1; j++) {
      if (tmp[j] == 'o') {
        b[0].push_back(rot(i, j, 0));
        b[1].push_back(rot(i, j, 1));
        b[2].push_back(rot(i, j, 2));
        b[3].push_back(rot(i, j, 3));
      }
    }
  }
  dbg(b);

  int old_x = -1, old_y = -1;
  int new_x = -1, new_y = -1;
  sort(a.begin(), a.end());
  bool ok = false;
  auto find_ans = [&](vector<pair<int, int>> &cur) -> void {
    for (int k = 0; k < 2; k++) {
      if (ok) {
        break;
      }
      for (int id : {int(0), (int)a.size() - 1}) {
        if (ok) {
          break;
        }
        set<pair<int, int>> c1{cur.begin(), cur.end()};
        pair<int, int> beg;
        if (id == 0) {
          beg = *c1.begin();
        } else {
          beg = *c1.rbegin();
        }

        if (id != 0) {
          reverse(a.begin(), a.end());
        }
        if (k == 1 && a.size() > 1) {
          swap(a[0], a[1]);
        }
        int dx = a[0].first - beg.first, dy = a[0].second - beg.second;
        dbg(dx, dy);
        vector<int> lo;
        for (auto i = 0; i < int(a.size()); i++) {
          int cx = a[i].first - dx;
          int cy = a[i].second - dy;
          if (c1.find({cx, cy}) == c1.end()) {
            lo.push_back(i);
          } else {
            c1.erase({cx, cy});
          }
        }

        if (lo.size() == 0) {
          new_x = old_x = a[0].first;
          new_y = old_y = a[0].second;
          ok = true;
        } else if (lo.size() == 1) {
          old_x = a[lo[0]].first;
          old_y = a[lo[0]].second;
          auto [c_x, c_y] = *c1.begin();
          new_x = dx + c_x;
          new_y = dy + c_y;
          ok = true;
        }

        if (k == 1 && a.size() > 1) {
          swap(a[0], a[1]);
        }
        if (id != 0) {
          reverse(a.begin(), a.end());
        }
      }
    }
  };

  for (int i = 0; !ok && i < 4; i++) {
    find_ans(b[i]);
  }

  cout << old_y << ' ' << old_x << '\n' << new_y << ' ' << new_x << '\n';
}
