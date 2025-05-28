/**
 * Author: distiled
 */
#include <cassert>
#include <iostream>
using namespace std;

#include "testlib.h"
#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  registerGen(argc, argv, 1);
  int tt = opt<int>("t");
  int N = opt<int>("N");
  int M = opt<int>("M");
  int CNT = opt<int>("CNT");
  int weight_k = opt<int>("wk");
  int weight_aij = opt<int>("wa"); // accepts 0, 1, 2
  assert(weight_aij >= 0 && weight_aij <= 2);
  cout << tt << '\n';
  const int BIAS = weight_k;
  // const int MX = 1'000'000'000;
  const int MX = 100;
  vector<int> ns = rnd.partition(tt, N);
  vector<int> ms = rnd.partition(tt, M);
  for (int ttt = 0; ttt < tt; ttt++) {
    // if (rnd.next(2)) {
    //   swap(ns[ttt], ms[ttt]);
    // }
    int n = ns[ttt], m = ms[ttt];
    int mn = min(n, m);
    int k;
    int cnt = min(n * m, CNT);
    if (!weight_k) {
      k = rnd.next(1, mn);
    } else {
      k = rnd.wnext(max(1, mn / 2), BIAS) + 1;
      k = rnd.next(2) ? mn - k + 1 : k;
    }
    if (k % 2 == 0) {
      k -= 1;
    }
    vector<int> cands(cnt);
    for (int i = 0; i < cnt; i++) {
      cands[i] = rnd.next(MX + 1);
    }
    sort(cands.begin(), cands.end());
    cout << n << ' ' << m << ' ' << k << '\n';
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!weight_aij) {
          // a[i][j] = rnd.next(0, MX);
          a[i][j] = cands[rnd.next(cnt)];
        } else {
          // a[i][j] = rnd.wnext(MX + 1, (i + j) * (weight_aij == 1 ? -1 : 1));
          a[i][j] = cands[rnd.wnext(cnt, (i + j) * (weight_aij == 1 ? -1 : 1))];
        }
      }
    }
    for (int i = 0; i < n; i++) {
      println(a[i]);
    }
  }
}
