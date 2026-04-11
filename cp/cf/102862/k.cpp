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

const int N = 1e5 + 5;

int p[N];
int cnt[N];

int find(int u) {
  if (p[u] == u)
    return u;
  return p[u] = find(p[u]);
}

void unite(int u, int v) {
  u = find(u);
  v = find(v);
  p[v] = u;
  cnt[u] += cnt[v];
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    p[i] = i;
    int t;
    cin >> t;
    cnt[i] = t;
  }

  int m;
  cin >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;

    if (find(a) != find(b)) {
      unite(a, b);
    }
  }

  for (int i = 1; i <= n; i++) {
    if (cnt[find(i)] & 1) {
      cout << "NO\n";
      return 0;
    }
  }

  cout << "YES\n";
}
