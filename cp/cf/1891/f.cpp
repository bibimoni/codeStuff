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
#define int long long

const int N = (int) 5e5 + 5, INF = (int) 1e18;
vector<int> adj[N];

struct Query {
  int t, v, x;
};

int st[N], en[N], m = 0, n;

void dfs(int u, int p = -1) {
  st[u] = ++m;
  for(int v : adj[u]) {
    if(v == p)
      continue;
    dfs(v, u);
  }
  en[u] = m;
}

template <class T>
class fenwick {
  vector<T> a;
  int n;

public:
  fenwick() {}

  fenwick(int n_) : n(n_) {
    // check initial value
    a.assign(n + 5, static_cast<T>(0));
  }

  T query(int r) {
    T q = 0; // check default value of query
    for (; r > 0; r -= (r & -r)) {
      q += a[r]; // check query modification
    }
    return q;
  }

  void update(int r, T del) {
    for (; r <= n; r += (r & -r)) {
      a[r] += del; //check update rule
    }
  }
  void range(int l, int r, int val) {
    update(l, val);
    update(r + 1, -val);
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int q;
    cin >> q;
    m = 0, n = 1;
    vector<Query> query(q);
    for (int i = 0; i < q; i++) {
      cin >> query[i].t >> query[i].v;
      if (query[i].t == 2)
        cin >> query[i].x;
      else
        n++;
    }
    for (int i = 1; i <= n; i++) {
      en[i] = 0;
      st[i] = 0;
      adj[i].clear();
    }
    int sz = 1;
    for(auto [t, v, x] : query) {
      if (t == 2) 
        continue;
      adj[v].push_back(++sz);
      adj[sz].push_back(v);
    }
    dfs(1);
    fenwick<int> ft(n + 1);
    sz = 1;
    for(auto [t, v, x] : query) {
      if(t == 1) { 
        int node = st[++sz];
        int x = ft.query(node);
        ft.range(node, node, -x);
      }
      else {
        ft.range(st[v], en[v], x);
      }
    }
    for(int i = 1; i <= n; i++) {
      cout << ft.query(st[i]) << " \n"[i == n];
    }
  }
}


