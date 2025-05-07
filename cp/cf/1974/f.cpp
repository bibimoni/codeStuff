// time-limit: 3000
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
#define int            long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b, n, m;
    cin >> a >> b >> n >> m;
    vector<int> tx, ty;
    map<int, set<int>> rows, cols;
    for (int i = 1; i <= n; i++) {
      int x, y;
      cin >> x >> y;
      tx.push_back(x);
      ty.push_back(y);
      rows[x].insert(y);
      cols[y].insert(x);
    }
    sort(tx.begin(), tx.end());
    tx.erase(unique(tx.begin(), tx.end()), tx.end());
    sort(ty.begin(), ty.end());
    ty.erase(unique(ty.begin(), ty.end()), ty.end());
    deque<int> xs(tx.begin(), tx.end()), ys(ty.begin(), ty.end());    
    auto bs1 = [&] (int val, deque<int> &dq) -> int {
      int l = 0, r = dq.size() - 1, ret = -1;
      while(l <= r) {
        int m = (l + r) >> 1;
        if(val >= dq[m]) {
          l = m + 1;
          ret = m;
        }
        else {
          r = m - 1;
        }
      }
      return ret;
    };
    auto bs2 = [&] (int val, deque<int> &dq) -> int {
      int l = 0, r = dq.size() - 1, ret = -1;
      while(l <= r) {
        int m = (l + r) >> 1;
        if(val <= dq[m]) {
          r = m - 1;
          ret = m;
        }
        else {
          l = m + 1;
        }
      }
      return ret;
    };
    vector<int> d = {0, a + 1, 0, b + 1};
    set<pair<int, int>> out;
    int turn = 0;
    vector<int> ans(2, 0);
    while(m--) {
      int k;
      char c;
      cin >> c >> k;
      if (!xs.size() || !ys.size()) {
        continue;
      }
      if (c == 'U') {
        d[0] += k;
        int id = bs1(d[0], xs);
        if (id == -1) {
          (turn += 1) %= 2;
          continue;
        }
        for (int i = id; i >= 0; i--) {
          int x = xs[i];
          for (auto y : rows[x]) {
            if (out.find({x, y}) != out.end()) {
              continue;
            }
            ans[turn]++;
            out.insert({x, y});
          }
        }
        for (int i = id; i >= 0 && xs.size(); i--) {
          xs.pop_front();
        }

      } else if (c == 'D') {
        d[1] -= k;
        int id = bs2(d[1], xs);
        if (id == -1) {
          (turn += 1) %= 2;
          continue;
        }
        for (int i = id; i < xs.size(); i++) {
          int x = xs[i];
          for (auto y : rows[x]) {
            if (out.find({x, y}) != out.end()) {
              continue;
            }
            ans[turn]++;
            out.insert({x, y});
          }
        }
        int tmp = xs.size();
        for (int i = id; i < tmp && xs.size(); i++) {
          xs.pop_back();
        }

      } else if (c == 'L') {
        d[2] += k;
        int id = bs1(d[2], ys);
        if (id == -1) {
          (turn += 1) %= 2;
          continue;
        }
        for (int i = id; i >= 0; i--) {
          int y = ys[i];
          for (auto x : cols[y]) {
            if (out.find({x, y}) != out.end()) {
              continue;
            }
            ans[turn]++;
            out.insert({x, y});
          }
        }
        for (int i = id; i >= 0 && ys.size(); i--) {
          ys.pop_front();
        }

      } else if (c == 'R') {
        d[3] -= k;
        int id = bs2(d[3], ys);
        if (id == -1) {
          (turn += 1) %= 2;
          continue;
        }
        for (int i = id; i < ys.size(); i++) {
          int y = ys[i];
          for (auto x : cols[y]) {
            if (out.find({x, y}) != out.end()) {
              continue;
            }
            ans[turn]++;
            out.insert({x, y});
          }
        }
        int tmp = ys.size();
        for (int i = id; i < tmp && ys.size(); i++) {
          ys.pop_back();
        }
      }
      (turn += 1) %= 2;
    }
    cout << ans[0] << ' ' << ans[1] << '\n';
  }
}


