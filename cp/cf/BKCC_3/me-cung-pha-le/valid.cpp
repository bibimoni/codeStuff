#include "testlib.h"

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
using namespace std;

int main(int argc, char *argv[]) {
  const int M = 2e6 + 1;
  vector<int> ok(M, 1);
  ok[0] = 0, ok[1] = 0;
  for (int i = 2; i <= M; i++) {
    if (ok[i]) {
      for (int j = i * i; j <= M; j += i) {
        ok[j] = 0;
      }
    }
  }
  registerValidation(argc, argv);
  // int tcc = inf.readInt(1, 100, "t");
  // inf.readEoln();
  //
  // for (int tc = 1; tc <= tcc; tc++) {
  int n = inf.readInt(2, 500000, "n");
  inf.readSpace();
  int m = inf.readInt(0, 100000, "m");
  inf.readEoln();
  inf.readInts(n, 1, 2000000, "a");
  inf.readEoln();
  if (m > 0) {
    auto b = inf.readInts(m, 1, 2000000, "b");
    for (int x : b) {
      if (!ok[x]) {
        inf.quitf(_wa, "b contains non-prime %d", x);
      }
    }
    inf.readEoln();
  }
  // }
  inf.readEof();
}
