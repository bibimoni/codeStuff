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
#define int int64_t 

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  vector<pair<int, int>> coords(n);
  map<int, vector<int>> rows;
  map<int, vector<int>> cols;
  for (int i = 0; i < n; i++) {
    cin >> coords[i].first >> coords[i].second;
    rows[coords[i].first].push_back(coords[i].second);
    cols[coords[i].second].push_back(coords[i].first);
  }
  map<int, vector<int>> prows;
  map<int, vector<int>> pcols;
  for (auto &[k, p] : rows) {
    sort(p.begin(), p.end());
    prows[k].assign(p.size() + 1, int(0));
  }
  for (auto &[k, p] : cols) {
    sort(p.begin(), p.end());
    pcols[k].assign(p.size() + 1, int(0));
  }
  auto go = [&] (vector<int> &f, vector<int> &p, int l, int r) -> void {
    if (f.size() == 0) {
      return;
    }
    int lo = 0, hi = f.size() - 1, ll = -1;
    // l
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      if (f[mid] < l) {
        lo = mid + 1;
      } else {
        hi = mid - 1;
        ll = mid;
      }
    }
    if (ll == -1) {
      return;
    }
    // r
    lo = 0, hi = f.size() - 1;
    int rr = -1;
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      if (f[mid] > r) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
        rr = mid;
      }
    }
    if (rr == -1) {
      return;
    }
    p[ll] += 1;
    p[rr + 1] -= 1;
  };
  for (int i = 0; i < m; i++) {
    char c; int off;
    cin >> c >> off;
    if (c == 'U') {
      go(rows[x], prows[x], y, y + off);
      y += off;
    } else if (c == 'D') {
      go(rows[x], prows[x], y - off, y);
      y -= off;
    } else if (c == 'L') {
      go(cols[y], pcols[y], x - off, x);
      x -= off;
    } else if (c == 'R') {
      go(cols[y], pcols[y], x, x + off);
      x += off;
    }
  }
  set<pair<int, int>> st;
  for (auto &[k, p] : prows) {
    for (int i = 1; i < int(p.size()); i++) {
      p[i] += p[i - 1];
    }
  }
  for (auto &[k, p] : rows) {
    for (int i = 0; i < int(p.size()); i++) {
      if (prows[k][i] > 0) {
        st.insert({k, p[i]});
      }
    }
  }
  for (auto &[k, p] : pcols) {
    for (int i = 1; i < int(p.size()); i++) {
      p[i] += p[i - 1];
    }
  }
  for (auto &[k, p] : cols) {
    for (int i = 0; i < int(p.size()); i++) {
      if (pcols[k][i] > 0) {
        st.insert({p[i], k});
      }
    }
  }
  cout << x << ' ' << y << ' ' << st.size();
}


