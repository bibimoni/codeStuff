#include <bits/stdc++.h>
#include "testlib.h"
 
using namespace std;
 
int main(int argc, char *argv[]) {
  registerValidation(argc, argv);
  int t = inf.readInt(1, 100, "t");
  inf.readEoln();
  int sum = 0;
  while (t--) {
    int n = inf.readInt(1, (int) 2e5, "n");
    inf.readEoln();
    inf.readInts(m, 0, (int) n, "aij");
    inf.readEoln();
    sum += n;
  }
  ensuref(sum <= int(2e5), "total n must be less or equal than 2e5");
  inf.readEof();
}
