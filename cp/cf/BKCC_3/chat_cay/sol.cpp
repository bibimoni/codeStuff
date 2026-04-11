/**
 * Author: distiled
 */
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
#define int int64_t

struct Q {
  int opt;
  int x, u, y;
};

class Dsu {
  vector<int> parent, siz;
  int count_cp;

public:
  multiset<int> st;
  vector<int> val;
  Dsu() {}

  Dsu(int n, vector<int> &b) : val(b) {
    count_cp = n - 1; // Dsu uf(n + 1) so we need to subtract 1
    parent.resize(n);
    siz.assign(n, 1);
    st = multiset<int>{val.begin() + 1, val.end()};
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
      st.erase(st.find(val[a]));
      st.erase(st.find(val[b]));
      val[a] += val[b];
      st.insert(val[a]);
      count_cp -= 1;
      return true;
    } else {
      return false;
    }
  }

  int size(int u) { return siz[find(u)]; }

  int size() { return count_cp; }

  int get(int u) {
    int r = find(u);
    return val[r];
  }

  void upd(int u, int d) {
    int r = find(u);
    st.erase(st.find(val[r]));
    val[r] += d;
    st.insert(val[r]);
  }

  bool same(int u, int v) { return find(u) == find(v); }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<pair<int, int>> edges;
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      edges.push_back({u, v});
    }

    vector<int> was(n - 1, 1);
    vector<Q> que;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
      int opt;
      cin >> opt;
      Q qq;
      qq.opt = opt;
      if (opt == 1) {
        int x;
        cin >> x;
        x -= 1;
        was[x] = 0;
        qq.x = x;
      } else if (opt == 2) {
        int u, y;
        cin >> u >> y;
        qq.u = u;
        qq.y = y;
        a[u] += y;
      }
      que.push_back(qq);
    }

    Dsu dsu(n + 1, a);
    for (int i = 0; i < n - 1; i++) {
      if (was[i]) {
        auto [u, v] = edges[i];
        dsu.unite(u, v);
      }
    }

    vector<int> ans;
    reverse(que.begin(), que.end());
    for (Q qq : que) {
      if (qq.opt == 1) {
        auto [u, v] = edges[qq.x];
        ans.push_back(abs(dsu.get(u) - dsu.get(v)));
        dsu.unite(u, v);
      } else if (qq.opt == 2) {
        dsu.upd(qq.u, -qq.y);
      } else {
        ans.push_back(*dsu.st.begin());
      }
      dbg(ans);
    }

    reverse(ans.begin(), ans.end());
    for (int x : ans) {
      cout << x << '\n';
    }
  }
}
