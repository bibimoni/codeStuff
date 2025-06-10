/**
 * Author: distiled
 */
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <list>
#include <numeric>
#include <random>
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
  int n = opt<int>("n");
  int cnt = 0;
  vector<array<int, 3>> f1;
  vector<vector<int>> f2;
  vector<vector<int>> f3;
  for (int a = 0; a < (1 << n); a++) {
    for (int b = 0; b < (1 << n); b++) {
      int m = __builtin_popcount(a);
      int t = __builtin_popcount(b);
      if (m <= 2 || t <= 2) {
        continue;
      }
      // cout << n << ' ' << m << ' ' << t << '\n';
      f1.push_back({n, m, t});
      cnt += 1;

      vector<int> ar, br;
      for (int i = 0; i < n; i++) {
        if ((a >> i) & 1) {
          ar.push_back(i + 1);
        }
        if ((b >> i) & 1) {
          br.push_back(i + 1);
        }
      }
      f2.push_back(ar);
      f3.push_back(br);
    }
  }
  vector<int> p(cnt);
  iota(p.begin(), p.end(), 0);
  shuffle(p.begin(), p.end());
  const int BOUND = 500;
  cnt = min(cnt, BOUND);
  cout << cnt << "\n";
  for (int i = 0; i < cnt; i++) {
    println(f1[p[i]]);
    println(f2[p[i]]);
    println(f3[p[i]]);
  }
}
