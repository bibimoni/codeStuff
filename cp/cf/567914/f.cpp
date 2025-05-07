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
int C(int n, int k) {
  double res = 1;
  for(int i = 1; i <= k; i++) {
    res = res * (n - k + i) / i;
  }
  return (int) res;
}
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  // freopen("dulich.inp", "r", stdin);
  // freopen("dulich.out", "w", stdout);
  int n, a, b;
  cin >> n >> a >> b;
  vector<vector<pair<int, int>>> adj(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, min(b, a * w)});
    adj[v].push_back({u, min(b, a * w)});
  }

}

