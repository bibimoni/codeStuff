#include <bits/stdc++.h>
#include "../testlib.h"
 
using namespace std;
 
int main(int argc, char *argv[]) {
  registerValidation(argc, argv);
  int t = inf.readInt(1, 100, "t");
  inf.readEoln();
  int sum = 0;
  while (t--) {
    int n = inf.readInt(1, (int) 1e5, "n");
    inf.readSpace();
    int m = inf.readInt(1, (int) 1e5, "m");
    inf.readEoln();
    for (int i = 0; i < n; i++) {
      inf.readInts(m, 0, (int) 1e6, "aij");
      inf.readEoln();
    }
    int q = inf.readInt(1, (int) 1e5, "q");
    sum += n * m + q;
    inf.readEoln();
    while (q--) {
      int a = inf.readInt(1, n, "a");
      inf.readSpace();
      int b = inf.readInt(1, m, "b");
      inf.readSpace();
      int c = inf.readInt(a, n, "c");
      inf.readSpace();
      int d = inf.readInt(b, m, "d");
      inf.readSpace();
      int k = inf.readInt(1, (int) 1e6, "k");
      inf.readEoln();
    }
  }
  ensuref(sum <= int(2e5), "total n * m + q must be less or equal than 2e5");
  inf.readEof();
}
