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
  int n = opt<int>("n");
  int tt = (1 << (2 * n)) - (2 * (1 << n) - 1);
  cout << tt << '\n';
  int cnt = 0;
  for (int a = 0; a < (1 << n); a++) {
    for (int b = 0; b < (1 << n); b++) {
      int m = __builtin_popcount(a);
      int t = __builtin_popcount(b);
      if (!m || !t) {
        continue;
      }
      cout << n << ' ' << m << ' ' << t << '\n';
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
      println(ar);
      println(br);
    }
  }
  dbg(tt, cnt);
  assert(cnt == tt);
}
