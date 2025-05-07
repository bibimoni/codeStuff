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

const int N = 3e5 + 5, LG = 20;
int n, m;
vector<int> adj[N];
int L[N];
int s[N], t[N], w[N];
int par[N][LG], dep[N];
int pre[N];
int ans[N];

template <class T>
struct LazySegTree {
  vector<pair<int, int>> st, lazy;
  int n;
  LazySegTree() {}

  LazySegTree(int _n) : n(_n) {
    T default_value = 0;
    st.assign(4 * n + 5, {0, 0});
    lazy.assign(4 * n + 5, {0, 0});
  }  
  void build(const vector<T> &a) {
    build(a, 1, 1, n);
  }
  void build(const vector<T> &a, int id, int l, int r) {
    lazy[id] = {0, 0};
    if(l == r) {
      if(l < a.size()) {
        st[id] = {0, L[l]};
      }
      return;
    }
    int mid = (l + r) >> 1;
    build(a, id * 2, l, mid);
    build(a, id * 2 | 1, mid + 1, r);
    st[id] = max(st[id * 2], st[id * 2 | 1]);
  }
  void down(int id) {
    if(lazy[id] == 0)
      return;
    st[id * 2] += lazy[id];
    st[id * 2 | 1] += lazy[id];
    lazy[id * 2] += lazy[id];
    lazy[id * 2 | 1] += lazy[id];
    lazy[id] = 0;
  }
  void update(int u, int v, T val) {
    update(u, v, val, 1, 1, n);
  }
  void update(int u, int v, T val, int id, int l, int r) {
    if(v < l || r < u) return;
    if(u <= l && r <= v) {
      lazy[id] += val;
      st[id] += val;
      return;
    }
    down(id);
    int mid = (l + r) >> 1;
    update(u, v, val, id * 2, l, mid);
    update(u, v, val, id * 2 | 1, mid + 1, r);
    st[id] = max(st[id * 2], st[id * 2 | 1]);
  }
  T query(int u, int v) {
    return query(u, v, 1, 1, n);
  }
  T query(int u, int v, int id, int l, int r) {
    if(v < l || r < u) {
      return 0;
    }
    if(u <= l && r <= v) {
      return st[id];
    }
    int mid = (l + r) >> 1;
    down(id);
    return max(query(u, v, id * 2, l, mid), query(u, v, id * 2 | 1, mid + 1, r));
  }
};

template <class T>
struct HeavyLight {
  LazySegTree<T> seg;
  vector<int> parent, depth, heavy, head, pos;
  int cur_pos;

  int dfs(int u) {
    int size = 1;
    int max_c_size = 0;
    for (int c : adj[u]) {
      if (c == parent[u]) continue;
      parent[c] = u, depth[c] = depth[u] + 1;
      int c_size = dfs(c);
      size += c_size;
      if (c_size > max_c_size) {
        max_c_size = c_size;
        heavy[u] = c;
      }
    }
    return size;
  }

  void decomp(int v, int h) {
    head[v] = h;
    pos[v] = cur_pos++; // position of v in segtree
    if (~heavy[v]) {
      decomp(heavy[v], h);
    }
    for (int c : adj[v]) {
      if (c != parent[v] && c != heavy[v]) {
        decomp(c, c);
      }
    }
  }

  HeavyLight() {
    seg = LazySegTree<int>(N);
    parent = vector<int>(N);
    depth = vector<int>(N);
    heavy = vector<int>(N, -1);
    head = vector<int>(N);
    pos = vector<int>(N);
    cur_pos = 1;
    dfs(1);
    decomp(1, 0);
  }

  void update(int a, int b, T val) {
    for (; head[a] != head[b]; b = parent[head[b]]) {
      if (depth[head[a]] > depth[head[b]]) swap(a, b);
      seg.update(pos[head[b]], pos[b], val);
    }
    if (depth[a] > depth[b]) swap(a, b);
    seg.update(pos[a], pos[b], val);
  }

  T query(int a, int b) {
    T res = 0; // default value for query
    for (; head[a] != head[b]; b = parent[head[b]]) {
      if (depth[head[a]] > depth[head[b]]) swap(a, b);
      T cur = seg.query(pos[head[b]], pos[b]);
      // operation
      res += cur;
    }
    if (depth[a] > depth[b]) swap(a, b);
    T lst = seg.query(pos[a], pos[b]);
    // operation
    res += lst;
    return res;
  }
};

void dfs(int u, int p = 0) {
  par[u][0] = p;
  for (int i = 1; i < LG; i++) {
    par[u][i] = par[par[u][i - 1]][i - 1];
  }
  for (int v : adj[u]) {
    if (v == p) {
      continue;
    }
    dep[v] = dep[u] + 1;
    dfs(v, u);
  }
}

int dad(int u, int k) {
  for (int i = LG - 1; i >= 0; i--) {
    if ((k >> i) & 1) {
      u = par[u][i];
    }
  }
  return u;
}

int lca(int u, int v) {
  if (dep[u] < dep[v]) {
    swap(u, v);
  }
  u = dad(u, dep[u] - dep[v]);
  if (u == v) {
    return u;
  }
  for (int i = LG - 1; i >= 0; i--) {
    if (par[u][i] != par[v][i]) {
      u = par[u][i];
      v = par[v][i];
    }
  }
  return par[u][0];
}

int dist(int u, int v) {
  int f = lca(u, v);
  return dep[u] + dep[v] - 2 * dep[f]; 
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  bool zero = true;
  for (int i = 1; i <= n; i++) {
    cin >> L[i];
    ans[i] = 0;
    zero &= L[i] == 0;
  }
  for (int i = 1; i <= m; i++) {
    cin >> s[i] >> t[i] >> w[i];
  }
  HeavyLight<int> hld;
  dfs(1);
  if (zero) {
    for (int i = 1; i <= m; i++) {
      // cout << dist(s[i], t[i]) * w[i] << ' ';
      hld.update(s[i], t[i], w[i]);
    }
    for (int i = 1; i <= n; i++) {
      cout << hld.query(i, i) << ' ';
    }
  } else if (n <= 100 && m <= 100) {
    for (int i = 1; i <= m; i++) {
      int f = lca(s[i], t[i]);
      int u = s[i], v = t[i];
      while (u != f) {
        ans[u] += max(-L[u] + w[i], int(0));
        u = par[u][0];
      } 
      while (v != f) {
        ans[v] += max(-L[v] + w[i], int(0));
        v = par[v][0];
      } 
      ans[f] += max(-L[f] + w[i], int(0));
    }
    for (int i = 1; i <= n; i++) {
      cout << ans[i] << " \n"[i == n];
    }
  } else {
    // straight line

  }
}


