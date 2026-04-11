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

class Dsu {
  int count_cp;

public:
  vector<int> parent, siz;
  vector<int> ce, cv;
  Dsu() {}

  Dsu(int n) {
    count_cp = n - 1; // Dsu uf(n + 1) so we need to subtract 1
    parent.resize(n);
    siz.assign(n, 1);
    ce.assign(n, 0);
    iota(parent.begin(), parent.end(), 0ll);
  }

  int find(int v) {
    if (v == parent[v]) {
      return v;
    }
    return parent[v] = find(parent[v]);
  }

  bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
      if (siz[a] < siz[b]) {
        swap(a, b);
      }
      parent[b] = a;
      siz[a] += siz[b];
      ce[a] += ce[b] + 1;
      count_cp -= 1;
      return true;
    } else {
      ce[a] += 1;
      return false;
    }
  }

  int size(int u) { return siz[find(u)]; }

  int size() { return count_cp; }

  bool same(int u, int v) { return find(u) == find(v); }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> a;
  vector<int> cands;
  for (int i = 0; i < n; i++) {
    int x, r;
    cin >> x >> r;
    a.emplace_back(x, r);
    cands.push_back(x - r);
    cands.push_back(x + r);
  }

  sort(cands.begin(), cands.end());
  cands.erase(unique(cands.begin(), cands.end()), cands.end());
  dbg(cands);

  int m = (int)cands.size();
  Dsu dsu(m + 1);
  for (int i = 0; i < n; i++) {
    auto [x, r] = a[i];
    int c1 = x - r, c2 = x + r;
    int u1 = lower_bound(cands.begin(), cands.end(), c1) - cands.begin() + 1;
    int u2 = lower_bound(cands.begin(), cands.end(), c2) - cands.begin() + 1;
    dsu.unite(u1, u2);
  }

  int ans = 0;
  for (int i = 1; i <= m; i++) {
    int r = dsu.find(i);
    if (r == i) {
      ans += min(dsu.siz[r], dsu.ce[r]);
    }
  }

  cout << ans << '\n';
}
