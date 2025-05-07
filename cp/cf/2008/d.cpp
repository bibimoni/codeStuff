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

class Dsu {
  vector<int> parent, size;

public:
  vector<int> cntW;
  Dsu() {}
 
  Dsu(int n) {
    parent.resize(n);
    size.assign(n, 1);
    iota(parent.begin(), parent.end(), 0ll);
    cntW.assign(n, 0);
  }
 
  int find(int v) {
    if (v == parent[v]) {
      return v;
    }
    return parent[v] = find(parent[v]);
  }
 
  bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
      if (size[a] < size[b]) {
        swap(a, b);
      }
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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    Dsu dsu(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> p[i];
    }
    string s;
    cin >> s;
    s = " " + s;
    for (int i = 1; i <= n; i++) {
      if (dsu.find(i) == i) {
        if (s[i] == '0') {
          dsu.cntW[dsu.find(i)] += 1;
        }
        int cur = p[i];
        while (cur != i) {
          dsu.unite(i, cur);
          if (s[cur] == '0') {
            dsu.cntW[dsu.find(i)] += 1;
          }
          cur = p[cur];
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      cout << dsu.cntW[dsu.find(i)] << " \n"[i == n];
    }
  }
}


