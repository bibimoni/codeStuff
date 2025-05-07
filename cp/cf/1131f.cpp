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

const int N = 15e4 + 5;
vector<int> adj[N];

class dsu {
  vector<int> parent, size, left, right;

public:
  dsu() {}
 
  dsu(int n) {
    parent.resize(n);
    left.resize(n);
    right.resize(n);
    size.assign(n, 1);
    iota(all(parent), 0);
    iota(all(left), 0);
    iota(all(right), 0);
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
      adj[right[a]].push_back(left[b]);
      adj[left[b]].push_back(right[a]);
      right[a] = right[b];
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
  int n;
  cin >> n;
  dsu dsu(n + 1);
  for(int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    dsu.unite(u, v);
  }
  int leaf = 1;
  for(int i = 1; i <= n; i++) {
    if(adj[i].size() == 1) {
      leaf = i;
      break;
    }
  }
  vector<int> ans;
  queue<int> q;
  q.push(leaf);
  vector<int> visited(n + 1, 0);
  while(q.size()) {
    int u = q.front();
    q.pop();
    if(visited[u])
      continue;
    visited[u] = true;
    ans.push_back(u);
    for(int v : adj[u]) {
      q.push(v);
    }
  }
  for(int u : ans)
    cout << u << ' ';
}

