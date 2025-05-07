#include<bits/stdc++.h>
#include "testlib.h"
 
using namespace std;
 
#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
 
class Dsu {
  vector<int> parent, siz;
  int count_cp;
public:
  Dsu() {}
 
  Dsu(int n) {
    count_cp = n - 1;
    parent.resize(n);
    siz.assign(n, 1);
    iota(parent.begin(), parent.end(), 0ll);
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
      if (siz[a] < siz[b]) {
        swap(a, b);
      }
      parent[b] = a;
      siz[a] += siz[b];
      count_cp -= 1;
      return true;
    } else {
      return false;
    }
  }
 
  int size(int u) {
    return siz[find(u)];
  }
 
  int size() {
    return count_cp;
  }
 
  bool same(int u, int v) {
    return find(u) == find(v);
  }
};
 
int main(int argc, char *argv[]) {
  registerTestlibCmd(argc, argv);
 
  int tt = inf.readInt();
  for (int j = 1; j <= tt; j++) {
    setTestCase(j); 
    int n = inf.readInt();
    int m = inf.readInt();
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
      int u = inf.readInt();
      int v = inf.readInt();
      edges.push_back({u, v});
    }
    int rem_ans = ans.readInt();
    for (int i = 0; i < rem_ans; i++) {
      int _ = ans.readInt();
    }
    int add_ans = ans.readInt();
    for (int i = 0; i < add_ans; i++) {
      int _ = ans.readInt();
          _ = ans.readInt();
    }
 
    Dsu uf(n + 1);
    int rem_ouf = ouf.readInt();
    vector<int> was(m, 0);
    int total_edges = m;
    for (int i = 0; i < rem_ouf; i++) {
      int idx  = ouf.readInt();
      if (idx <= 0 || idx > m) {
        quitf(_wa, "Invalid edge index: index = %d\n", idx);
      }
      if (was[idx - 1]) {
        quitf(_wa, "edge removed twice: index = %d\n", idx);        
      }
      was[idx - 1] = 1;
      total_edges -= 1;
    }
 
    for (int i = 0; i < m; i++) {
      if (!was[i]) {
        auto [u, v] = edges[i];
        if (!uf.unite(u, v)) {
          dbg(u, v);
          quitf(_wa, "The resulting graph isn't a tree (contain loop)\n");
        } 
      }
    }
 
    int add_ouf = ouf.readInt();
    for (int i = 0; i < add_ouf; i++) {
      int u = ouf.readInt();
      int v = ouf.readInt();
      if (u <= 0 || u > n || v <= 0 || v > n) {
        quitf(_wa, "invalid edge: u = %d, v = %d\n", u, v);
      }
      if (!uf.unite(u, v)) {
        dbg(u, v);
        quitf(_wa, "The resulting graph isn't a tree (contain loop)\n");
      }
      total_edges += 1;
    }
 
    if (total_edges != n - 1) {
      quitf(_wa, "The resulting graph isn't a tree (number of edges is not equal to n - 1)\n");
    }
    dbg(uf.size());
    if (uf.size() != 1) {
      quitf(_wa, "The resulting graph isn't a tree (isn't connected)\n");
    }
 
    int j_ans = rem_ans + add_ans;
    int p_ans = rem_ouf + add_ouf;
    if (j_ans < p_ans) {
      quitf(_wa, "jury has the better answer: j_ans = %d, p_ans = %d\n", j_ans, p_ans);
    } else if (j_ans == p_ans) {
      continue;
    } else {
      quitf(_fail, ":( participant has the better answer: j_ans = %d, p_ans = %d\n", j_ans, p_ans);
    }
  }
  quitf(_ok, "%d test cases(s)", tt);
}
