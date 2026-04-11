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

const int N = 2e5, LG = 30;
set<int> adj[N];
int p[N];
vector<pair<int, int>> que[N];
int ans[N];
int flg[N], nxt[N];
int jump[N][LG];
int d[N];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i] -= 1;
    adj[p[i]].insert(i);
  }

  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    x -= 1;
    y -= 1;
    que[x].push_back({y, i});
  }

  for (int i = 0; i < n; i++) {
    flg[i] = 0;
    nxt[i] = -1;
    d[i] = 0;
    ans[i] = 0;
  }

  map<int, int> mp;
  set<int> cur;
  int st = -1, ed = -1;
  auto dfs = [&](auto &&self, int u) -> bool {
    cur.insert(u);
    flg[u] = -1;
    int v = p[u];
    if (flg[v] == 0) {
      nxt[v] = u;
      if (self(self, v)) {
        return true;
      }
    } else if (flg[v] == -1) {
      st = v;
      ed = u;
      return true;
    }
    flg[u] = -2;
    return true;
  };

  for (int x = 0; x < n; x++) {
    if (flg[x] != 0) {
      continue;
    }
    cur.clear();
    dfs(dfs, x);
    vector<int> cycl{st};
    for (int u = ed; u != st; u = nxt[u]) {
      cycl.push_back(u);
    }
    reverse(cycl.begin(), cycl.end());

    set<pair<int, int>> mark;
    for (int i = 0; i < int(cycl.size()); i++) {
      int prev = cycl[(i + 1) % int(cycl.size())];
      adj[cycl[i]].erase(prev);
      adj[prev].erase(cycl[i]);
    }

    auto dfs2 = [&](auto &&self, int u, int p) -> void {
      cur.insert(u);
      flg[u] = -2;
      jump[u][0] = p;
      for (int j = 1; j < LG; j++) {
        jump[u][j] = jump[jump[u][j - 1]][j - 1];
      }
      for (int v : adj[u]) {
        d[v] = d[u] + 1;
        self(self, v, u);
      }
    };

    int idx = 0;
    for (auto u : cycl) {
      dfs2(dfs2, u, u);
      mp[u] = idx;
      idx += 1;
    }

    auto incycl = [&](int a, int b) -> int {
      if (mp[a] <= mp[b]) {
        return mp[b] - mp[a];
      }
      return cycl.size() - mp[a] + mp[b];
    };

    auto go = [&](int u, int k) -> int {
      for (int j = 0; j < LG; j++) {
        if ((k >> j) & 1) {
          u = jump[u][j];
        }
      }
      return u;
    };

    auto find_ans = [&](int a, int b) -> int {
      if (cur.find(b) == cur.end()) {
        return -1;
      }
      if (!mp.count(a) && !mp.count(b)) {
        if (d[a] < d[b]) {
          return -1;
        }
        int ans = d[a] - d[b];
        a = go(a, ans);
        if (a == b) {
          return ans;
        } else {
          return -1;
        }
      }
      if (!mp.count(b)) {
        return -1;
      }
      int ac = go(a, d[a]);
      int bc = go(b, d[b]);
      return d[a] + d[b] + incycl(ac, bc);
    };

    for (int u : cur) {
      for (auto [b, id] : que[u]) {
        ans[id] = find_ans(u, b);
      }
    }
  }

  for (int i = 0; i < q; i++) {
    cout << ans[i] << '\n';
  }
}
