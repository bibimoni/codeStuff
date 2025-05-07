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
#define int            long long
#define all(_x) (_x).begin(), (_x).end()

class dsu {
  vector<int> parent, size;

public:
  dsu() {}
 
  dsu(int n) {
    parent.resize(n);
    size.assign(n, 1);
    iota(all(parent), 0);
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
  int n, m;
  cin >> n >> m;
  dsu dsu(n + 1);
  vector<pair<int, vector<int>>> vertex(m);
  for(int i = 0; i < m; i++) {
    int k, c;
    cin >> k >> c;
    vertex[i].first = c;
    for(int j = 0; j < k; j++) {
      int x; 
      cin >> x;
      vertex[i].second.push_back(x);
    }
  }
  sort(vertex.begin(), vertex.end(), [&] (pair<int, vector<int>> i, pair<int, vector<int>> j) {
    return i.first < j.first;
  });
  int ans = 0;
  for(auto [c, a] : vertex) {
    for(int i = 0; i + 1 < a.size(); i++) {
      if(dsu.unite(a[i], a[i + 1])) {
        ans += c;
      }  
    }
  }
  int cnt = 0;
  for(int i = 1; i <= n; i++) {
    cnt += (dsu.find(i) == i);
  }
  if(cnt > 1) {
    cout << "-1\n";
  }
  else {
    cout << ans;
  }
}


