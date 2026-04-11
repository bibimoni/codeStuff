#include "testlib.h"
#include <iostream>
#include <numeric>

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
using namespace std;

class Dsu {
  vector<int> parent, siz;
  int count_cp;

public:
  Dsu() {}

  Dsu(int n) {
    count_cp = n - 1; // Dsu uf(n + 1) so we need to subtract 1
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

  int size(int u) { return siz[find(u)]; }

  int size() { return count_cp; }

  bool same(int u, int v) { return find(u) == find(v); }
};

int main(int argc, char *argv[]) {
  registerValidation(argc, argv);
  int tcc = inf.readInt(1, 1000, "t");
  inf.readEoln();
  int s0 = 0, sq = 0;

  const int MX = 1'000'000'000;
  for (int tc = 1; tc <= tcc; tc++) {
    setTestCase(tc);
    int n = inf.readInt(1, 200'000, "n");
    s0 += n;
    inf.readEoln();
    inf.readInts(n, -MX, MX, "a");
    inf.readEoln();

    Dsu dsu(n + 1);
    set<pair<int, int>> st;

    for (int i = 0; i < n - 1; i++) {
      int x = inf.readInt(1, n, "x_i");
      inf.readSpace();
      int y = inf.readInt(1, n, "y_i");
      inf.readEoln();

      ensuref(x != y, "Tree can't contain loop");
      ensuref(st.count({x, y}) == 0, "Tree can't contain multiple edges");
      st.insert({x, y});
      st.insert({y, x});
      ensuref(dsu.unite(x, y), "Tree can't contain cycle");
    }

    set<int> c1;
    int q = inf.readInt(1, 200'000, "q");
    sq += q;
    inf.readEoln();
    for (int i = 0; i < q; i++) {
      int opt = inf.readInt(1, 3, "opt");
      if (opt == 1) {
        inf.readSpace();
        int x = inf.readInt(1, n - 1, "x");
        ensuref(c1.find(x) == c1.end(), "Can't remove an already removed edge");
        c1.insert(x);
        inf.readEoln();
      } else if (opt == 2) {
        inf.readSpace();
        int u = inf.readInt(1, n, "u");
        inf.readSpace();
        int y = inf.readInt(-MX, MX, "del");
        inf.readEoln();
      } else {
        inf.readEoln();
      }
    }
  }
  ensuref(s0 <= 200'000 && sq <= 200'000,
          "Max n and q from all testcase must be in the valid range");
  inf.readEof();
}
