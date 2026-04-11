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

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<array<int, 4>> que(q);
  for (int i = 0; i < q; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    que[i] = array<int, 4>{c, a, b, 0};
  }

  multiset<array<int, 4>> st{que.begin(), que.end()};
  Dsu dsu(n);
  int ans = 0;
  while (st.size()) {
    auto [c, u, v, at] = *st.begin();
    st.erase(st.begin());
    int nxt_c = (st.size() ? (*st.begin())[0] : 1e18);
    int cur_c = c;
    while ((u == v || !dsu.same(u, v)) || dsu.size() != 1) {
      if (dsu.unite(u, v)) {
        ans += cur_c;
      }
      (u += (at == 0)) %= n;
      (v += (at == 1)) %= n;
      cur_c += 1;
      at ^= 1;
      if (cur_c > nxt_c) {
        break;
      }
    }
    if (cur_c != c) {
      st.insert({cur_c, u, v, at});
    }
  }

  cout << ans << '\n';
}
