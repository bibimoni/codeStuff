#include "testlib.h"
#include <iostream>
#include <numeric>
#include <vector>

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
using namespace std;

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  int tc = opt<int>("T");
  int N = opt<int>("N");
  int MX = opt<int>("MX");
  int Q = opt<int>("Q");

  vector<int> ns = rnd.partition(tc, N, 1);
  vector<int> qs = rnd.partition(tc, Q, 1);
  vector<int> opt{-5, 0, 5};

  int t = -1000, step = 2000 / (tc - 1);
  cout << tc << '\n';
  for (int j = 0; j < tc; j++) {
    dbg("test");
    int n = ns[j], q = qs[j];
    cout << n << '\n';
    for (int i = 0; i < n; i++) {
      cout << rnd.next(-MX, MX) << " \n"[i == n - 1];
    }
    vector<int> p(n);
    for (int i = 1; i < n; i++) {
      p[i] = rnd.wnext(i, t);
    }

    vector<int> perm(n);
    iota(perm.begin(), perm.end(), 0);
    shuffle(perm.begin() + 1, perm.end());

    vector<pair<int, int>> edges;
    for (int i = 1; i < n; i++) {
      if (rnd.next(2)) {
        edges.push_back({perm[i], perm[p[i]]});
      } else {
        edges.push_back({perm[p[i]], perm[i]});
      }
    }

    t += step;
    for (int i = 0; i < n - 1; i++) {
      cout << edges[i].first + 1 << ' ' << edges[i].second + 1 << '\n';
    }

    vector<int> ids(q);
    iota(ids.begin(), ids.end(), 0);
    shuffle(ids.begin(), ids.end());
    vector<vector<int>> que(q);

    vector<int> picked(n - 1);
    iota(picked.begin(), picked.end(), 0);
    shuffle(picked.begin(), picked.end());
    int bound = rnd.wnext(n, opt[rnd.next(3)]);
    bound = min(bound, q); // number of first query
    dbg(bound);

    int i = 0;
    for (i = 0; i < bound; i++) {
      que[ids[i]] = {1, picked[i] + 1};
    }

    int rem = q - bound;
    int nq3 = rnd.wnext(rem + 1, opt[rnd.next(3)]);
    for (; i < nq3 + bound; i++) {
      que[ids[i]].push_back(3);
    }

    for (; i < q; i++) {
      que[ids[i]] = {2, rnd.next(1, n), rnd.next(-MX, MX)};
    }

    cout << q << '\n';
    for (int i = 0; i < q; i++) {
      for (int j = 0; j < (int)que[i].size(); j++) {
        cout << que[i][j] << " \n"[j == int(que[i].size()) - 1];
      }
    }
  }
}
