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
  vector<int> parent, siz;
  int count_cp;

public:
  Dsu() {}

  Dsu(int n) {
    count_cp = n - 1; // Dsu uf(n + 1) so we need to subtract 1
    parent.resize(n);
    siz.assign(n, 1);
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
      count_cp -= 1;
      return true;
    } else {
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
  int h, w;
  cin >> h >> w;

  Dsu dsu(h * w + 1);
  vector<string> s(h);
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }

  auto out = [&](int x, int y) -> bool {
    return x == 0 || x == h - 1 || y == 0 || y == w - 1;
  };

  auto id = [&](int x, int y) -> int { return x * w + y; };

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] != '.') {
        continue;
      }
      if (i > 0 && s[i - 1][j] == '.') {
        dsu.unite(id(i, j), id(i - 1, j));
      }
      if (j > 0 && s[i][j - 1] == '.') {
        dsu.unite(id(i, j), id(i, j - 1));
      }
    }
  }

  vector<int> nok(h * w + 1);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (out(i, j) && s[i][j] == '.') {
        nok[dsu.find(id(i, j))] = 1;
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '#') {
        continue;
      }
      ans += dsu.find(id(i, j)) == id(i, j) && !nok[dsu.find(id(i, j))];
    }
  }
  cout << ans << '\n';
}
