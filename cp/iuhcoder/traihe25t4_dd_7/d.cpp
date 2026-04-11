/**
 * Author: distiled
 */
#include <bits/stdc++.h>
#include <filesystem>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
#define int int64_t

class Dsu {
  vector<int> parent, siz;
  int count_cp;

public:
  Dsu() {}

  Dsu(int n) {
    count_cp = n; // Dsu uf(n + 1) so we need to subtract 1
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

#define query array<int, 4>
bool operator<(const query aa, const query bb) { return aa[0] < bb[0]; }
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<array<int, 4>> que(q);
  auto next = [&](int p) { return (p + 1) % n; };
  for (int i = 0; i < q; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a != b)
      que[i] = array<int, 4>{c, a, b, 0};
    else
      que[i] = array<int, 4>{c + 1, a, next(a), 1};
  }

  sort(que.begin(), que.end());
  Dsu dsu(n);

  vector<int> was(n, 0);
  int res = 0;

  set<query> st{que.begin(), que.end()};
  while (st.size()) {
    auto [c, a, b, v] = *st.begin();
    st.erase(st.begin());

    if (!dsu.same(a, b)) {
      res += c;
      dsu.unite(a, b);
      if (v == 0) {
        if (1) {
          st.insert({c + 1, a, next(a), 1});
          // was[a] = 1;
        }
        if (1) {
          st.insert({c + 2, b, next(b), 1});
          // was[b] = 1;
        }
      } else {
        was[a] = 1;
        if (!was[b]) {
          st.insert({c + 2, b, next(b), 1});
        }
        was[b] = 1;
      }
    }
  }

  cout << res << endl;
}
