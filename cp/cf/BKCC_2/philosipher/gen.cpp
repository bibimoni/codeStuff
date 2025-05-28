/**
 * Author: distiled
 */
#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>
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
  int N = opt<int>("N");
  int tt = opt<int>("tt");
  cout << tt << '\n';
  while (tt--) {
    int n = rnd.next(1, N);
    int m = rnd.next(1, n);
    int t = rnd.next(1, n);
    cout << n << ' ';
    cout << m << ' ' << t << '\n';
    vector<int> p(n + 1);
    iota(p.begin() + 1, p.end(), 1);
    shuffle(p.begin() + 1, p.end());
    for (int i = 1; i <= m; i++) {
      cout << p[i] << " \n"[i == m];
    }
    shuffle(p.begin() + 1, p.end());
    for (int i = 1; i <= t; i++) {
      cout << p[i] << " \n"[i == t];
    }
  }
}
