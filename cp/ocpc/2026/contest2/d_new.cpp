// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC
// target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define int long long
#define ld long double
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
void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adjx(n + 1);
  vector<vector<int>> adjy(n + 1);
  Dsu dx(n + 1);
  Dsu dy(n + 1);
  for (int i = 1; i <= m; ++i) {
    int a;
    cin >> a;
    string s;
    cin >> s;
    int b;
    cin >> b;
    if (s[0] == 'l') {
      dy.unite(a, b);
      adjx[b].push_back(a);
    } else if (s[0] == 'r') {
      dy.unite(a, b);
      adjx[a].push_back(b);
    } else if (s[0] == 'a') {
      dx.unite(a, b);
      adjy[a].push_back(b);
    } else {
      dx.unite(a, b);
      adjy[b].push_back(a);
    }
  }
  for (int i = 1; i <= n; ++i) {
    int parx = dx.find(i);
    if (parx != i) {
      for (auto v : adjx[i])
        adjx[parx].push_back(v);
      adjx[i].clear();
    }
    int pary = dy.find(i);
    if (pary != i) {
      for (auto v : adjy[i])
        adjy[pary].push_back(v);
      adjy[i].clear();
    }
  }
  // for(int i = 1; i <= n; ++i) {
  //     cout << "cuong " << i << "\n";
  //     for(auto v : adjx[i]) cout << v << " ";
  //     cout << "\n";
  // }
  vector<int> colorx(n + 1, 0);
  vector<int> parentx(n + 1, -1);
  int cycle_startx = -1, cycle_endx = 0;
  auto dfsx = [&](auto self, int v) -> bool {
    colorx[v] = 1;
    for (int u : adjx[v]) {
      if (colorx[u] == 0) {
        parentx[u] = v;
        if (self(self, u))
          return true;
      } else if (colorx[u] == 1) {
        cycle_endx = v;
        cycle_startx = u;
        return true;
      }
    }
    colorx[v] = 2;
    return false;
  };
  vector<int> colory(n + 1, 0);
  vector<int> parenty(n + 1, -1);
  int cycle_starty = -1, cycle_endy = 0;
  auto dfsy = [&](auto self, int v) -> bool {
    colory[v] = 1;
    for (int u : adjy[v]) {
      if (colory[u] == 0) {
        parenty[u] = v;
        if (self(self, u))
          return true;
      } else if (colory[u] == 1) {
        cycle_endy = v;
        cycle_starty = u;
        return true;
      }
    }
    colory[v] = 2;
    return false;
  };
  for (int v = 1; v <= n; v++) {
    if (colorx[v] == 0 && dfsx(dfsx, v))
      break;
  }
  for (int v = 1; v <= n; v++) {
    if (colory[v] == 0 && dfsy(dfsy, v))
      break;
  }
  // cout << cycle_startx << " " << cycle_starty << "\n";
  if (cycle_startx != -1 || cycle_starty != -1) {
    cout << "NO\n";
    return;
  }
  auto topo = [&](vector<vector<int>> &adj) -> vector<int> {
    vector<int> ord;
    vector<int> deg(n + 1);
    for (int u = 1; u <= n; u++) {
      for (int v : adj[u]) {
        deg[v] += 1;
      }
    }

    queue<int> que;
    for (int u = 1; u <= n; u++) {
      if (deg[u] == 0) {
        que.push(u);
      }
    }

    while (que.size()) {
      int u = que.front();
      que.pop();
      ord.push_back(u);
      for (int v : adj[u]) {
        deg[v] -= 1;
        if (deg[v] == 0) {
          que.push(v);
        }
      }
    }
    return ord;
  };
  vector<int> topox = topo(adjx);
  vector<int> topoy = topo(adjy);
  vector<int> ansx(n + 1, 1e9);
  vector<int> ansy(n + 1, 1e9);
  reverse(topox.begin(), topox.end());
  reverse(topoy.begin(), topoy.end());
  int curx = 1, cury = 1;
  for (int i = 0; i < topox.size(); ++i) {
    ansx[topox[i]] = curx++;
  }
  for (int i = 1; i <= n; ++i) {
    ansx[i] = ansx[dx.find(i)];
  }
  for (int i = 0; i < topoy.size(); ++i) {
    ansy[topoy[i]] = cury++;
  }
  for (int i = 1; i <= n; ++i) {
    ansy[i] = ansy[dy.find(i)];
  }
  cout << "YES\n";
  for (int i = 1; i <= n; ++i) {
    cout << ansx[i] << " " << ansy[i] << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
}
