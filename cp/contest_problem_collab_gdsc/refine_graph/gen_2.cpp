/**
 * Author: distiled
 */
#include<iostream>
#include<cassert>
using namespace std;

#include "testlib.h"
#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif

int main(int argc, char * argv[]) {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  registerGen(argc, argv, 1);
  
  auto gen_tree = [&] (int n, int t) -> vector<pair<int, int>> {
    vector<int> p(n);
    for (int i = 1; i < n; i++)
      p[i] = rnd.wnext(i, t);

    vector<int> perm = rnd.perm(n);

    vector<pair<int, int>> edges;
    for (int i = 1; i < n; i++)
      if (rnd.next(2))
        edges.push_back(make_pair(perm[i] + 1, perm[p[i]] + 1));
      else
        edges.push_back(make_pair(perm[p[i]] + 1, perm[i] + 1));

    shuffle(edges.begin(), edges.end());
    return edges;
  };

  int tt = opt<int>("tt");
  int N = opt<int>("N");
  int M = opt<int>("M");
  vector<int> n_vert = rnd.partition(tt, N);
  dbg(n_vert);
  // vector<int> m_e = rnd.partition(tt, M, 0);
  int jump = 2000 / tt;
  int t = -1000;
  println(tt);
  for (int i = 0; i < tt; i++) {
    int n = n_vert[i];
    int m;
    // int m = m_e[i];
    dbg(n);
    // true => remove edge, false => add edge
    assert(n > 0);
    if (rnd.next(2) && n > 1) {
      m = rnd.wnext(n - 1, max(1, n / 100));
      dbg("0");
    } else {
      dbg("1", int64_t(n) * (int64_t(n) - int64_t(1)) / 2 + n);
      m = rnd.wnext(int64_t(n) * (n - int64_t(1)) / 2 + n, max(1, n / 100));
    }
    m = min(m, M);
    M -= m;
    auto edges = gen_tree(n, t);
    t += jump;
    
    if (m < n - 1) {
      int rem = rnd.next(n - 1 - m, n - 1);
      while (rem--) {
        edges.pop_back();
      }
    }
    
    assert(edges.size() <= m);
    while (edges.size() < m) {
      int u = rnd.next(1, n);
      int v = rnd.next(1, n);
      edges.push_back({u, v});
    }

    dbg(edges.size());
    assert(edges.size() == m);
    cout << n << ' ' << m << '\n';
    for (auto [u, v] : edges) {
      cout << u << ' ' << v << '\n';
    }
  }
}
