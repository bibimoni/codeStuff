/**
 * File              : vpc23_d.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 04.08.2023
 * Last Modified By  : distiled
 */
#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </home/distiled/templates/debug.h>
#else
#define dbg(x...)
#endif

#define double        long double
#define int           long long
#define all(x)        x.begin(), x.end()
#define rall(x)       x.rbegin(), x.rend()
#define sz(x)         (int) x.size()
#define __lcm(a, b)   (1ll * ((a) / __gcd((a), (b))) * (b))
#define YES           cout << "YES\n";
#define NO            cout << "NO\n";
#define mod           1000000007
#define endl          '\n'
#define TLE           ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MULTI         int t;cin>>t;while(t--)
#define INF           (int) 1e18
#define MAXN          (int) 1e6 + 5
#define TMP           (int) 0

int nxt() {int n; cin >> n; return n;}

struct Edge {
  int u, v; double c;
  Edge(int _u, int _v, double _c): u(_u), v(_v), c(_c) {};
};

struct Dsu {
  vector<int> parent;

  void init(int n) {
    parent.resize(n + 5, 0);
    for (int i = 1; i <= n; i++) parent[i] = i;
  }

  int find(int u) {
    if (parent[u] == u) return u;
    return parent[u] = find(parent[u]);
  }

  bool join(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return false;
    parent[v] = u;
    return true;
  }
} dsu;

double w, c;
int n, x[MAXN], y[MAXN];
vector<Edge> edges, newEdges;
double euclid(int i, int j) {
  return (double) (sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2)));
}

signed main() {
  TLE;
  int n; cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
  }
  x[0] = y[0] = TMP;
  cin >> w >> c;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(i != j) {
        edges.push_back({i, j, c * euclid(i, j)});
      }
    }
  }
  dsu.init(MAXN);
  sort(all(edges), [] (Edge &x, Edge &y) {
    return x.c < y.c;
  });
  double tmp = 0;
  for(auto e : edges) {
    if(!dsu.join(e.u, e.v)) continue;
    newEdges.push_back(e);
    tmp += e.c;
  }
  for(int i = 1; i <= n; i++) {
    newEdges.push_back({0, i, w});
  }
  dsu.init(MAXN);
  sort(all(newEdges), [] (Edge &x, Edge &y) {
    return x.c < y.c;
  });
  double ans = 0;
  for(auto e : newEdges) {
    if(!dsu.join(e.u, e.v)) continue;
    ans += e.c;
  }
  ans = min(ans, tmp);
  cout << fixed << setprecision(9) << ans;
}

