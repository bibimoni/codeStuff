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
#define all(_x) (_x).begin(), (_x).end()
const int N = (int) 1e3 + 5;
int w[N], b[N], weight, n, m;
vector<int> adj[N];
vector<int> grW, grB;
class dsu {
  vector<int> parent, size;
public:
  dsu() {}
 
  dsu(int n) {
    parent.resize(n);
    grW.resize(n);
    grB.resize(n);
    size.assign(n, 1);
    iota(all(parent), 0);
    for(int i = 1; i < n; i++) {
      grW[i] = w[i];
      grB[i] = b[i];
    }
  }
 
  int find(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find(parent[v]);
  }
 
  bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
      if (size[a] < size[b]) swap(a, b);
      parent[b] = a;
      grW[a] += grW[b];
      grB[a] += grB[b];
      size[a] += size[b];
      return true;
    } else {
      return false;
    }
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  cin >> n >> m >> weight;
  for(int i = 1; i <= n; i++) {
    cin >> w[i];
  }
  for(int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  dsu dsu(n + 1);
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    dsu.unite(u, v);
    // adj[u].push_back(v);
    // adj[v].push_back(u);
  }
  vector<int> tmp[n + 1];
  for(int i = 1; i <= n; i++) {
    tmp[dsu.find(i)].push_back(i);
  }
  vector<vector<int>> groups;
  int nGr = 0;
  groups.push_back({}); //for 1-indexed
  for(int i = 1; i <= n; i++) {
    if(tmp[i].size()) {
      groups.push_back(tmp[i]);
      nGr++;
    }
  }
  // dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - w][k] + b)
  // dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j - grW][k] + grB)
  // dp[i][j][2] = max(dp[i][j][2], dp[i - 1][j][k])
  // dbg(groups);
  // for(int i = 1; i <= nGr; i++) {
    // dbg(i, grW[dsu.find(groups[i][0])], grB[dsu.find(groups[i][0])]);
  // }
  vector<vector<vector<int>>> dp(nGr + 1, vector<vector<int>>(weight + 1, vector<int>(3, 0)));
  for(int i = 1; i <= nGr; i++) {
    for(int id : groups[i]) {
      int hosW = w[id], hosB = b[id];
      for(int j = 0; j <= weight; j++) {
        for(int k : {0, 1, 2}) {
          if(j >= hosW)
            dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - hosW][k] + hosB);
        }
      }
    }
    for(int j = 0; j <= weight; j++) {
      int gW = grW[dsu.find(groups[i][0])];
      int gB = grB[dsu.find(groups[i][0])];
      for(int k : {0, 1, 2}) {
        if(j >= gW)
          dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j - gW][k] + gB);
        dp[i][j][2] = max(dp[i][j][2], dp[i - 1][j][k]);
      }
    }
  }
  int ans = 0;
  for(int k : {0, 1, 2}) {
    ans = max(ans, dp[nGr][weight][k]);
  }
  cout << ans;
}

