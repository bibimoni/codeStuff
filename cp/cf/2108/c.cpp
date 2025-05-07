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

  int size(int u) {
    return siz[find(u)];
  }

  int size() {
    return count_cp;
  }

  bool same(int u, int v) {
    return find(u) == find(v);
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    Dsu dsu(n);
    vector<int> a(n);
    map<int, vector<int>, greater<int>> idx;
    vector<int> val(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      val[i] = a[i];
      idx[a[i]].push_back(i);
    }

    vector<int> was(n, -1);
    int ans = 0;
    const int INF = 1e9;
    int prev = INF;
    for (auto [k, p] : idx) {
      for (int v : p) {
        if (v + 1 < n && was[dsu.find(v + 1)] != -1) {
          was[v] = dsu.find(v + 1);
          dsu.unite(v + 1, v);
          val[dsu.find(v + 1)] = k;
        } else if (v - 1 >= 0 && was[dsu.find(v - 1)] != -1) {
          was[v] = dsu.find(v - 1);
          dsu.unite(v - 1, v);
          val[dsu.find(v - 1)] = k;
        } else {
          ans += 1;
          was[v] = dsu.find(v);
        }
      }
      prev = k;
    }
    cout << ans << '\n';
  }
}


