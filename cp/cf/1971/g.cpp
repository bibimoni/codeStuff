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
  vector<pair<vector<int>, vector<int>>> e;

  dsu() {}
 
  dsu(int n, vector<int> &a) {
    parent.resize(n);
    size.assign(n, 1);
    iota(all(parent), 0);
    e.resize(n);
    for(int i = 0; i < n; i++) {
      e[i] = {{i}, {a[i]}};
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
      size[a] += size[b];
      int k = e[b].first.size();
      for(int i = 0; i < k; i++) {
        e[a].first.push_back(e[b].first[i]);
        e[a].second.push_back(e[b].second[i]);
      }
      return true;
    } else {
      return false;
    }
  }
};

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    dsu dsu(n, a);
    map<int, int> f;
    for(int i = 0; i < n; i++) {
      for(int c : {0, 1, 2, 3}) {
        if(f.count(c ^ a[i])) {
          dsu.unite(f[c ^ a[i]], i);
        }
      }
      f[a[i]] = i;
    }
    vector<int> ans = a;
    vector<int> val;
    set<int> ids;
    for(int i = 0; i < n; i++) {
      int u = dsu.find(i);
      if(ids.find(u) == ids.end()) {
        ids.insert(u);
        vector<int> index = dsu.e[u].first;
        vector<int> vals = dsu.e[u].second;
        sort(index.begin(), index.end());
        sort(vals.begin(), vals.end());
        for(int i = 0; i < index.size(); i++) {
          ans[index[i]] = vals[i];
        }
      }
    }
    for(int i : ans)
      cout << i << ' ';
    cout << '\n';
  }
} 


