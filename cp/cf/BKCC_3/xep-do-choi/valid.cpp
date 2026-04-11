#include "testlib.h"

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
using namespace std;

int main(int argc, char *argv[]) {
  registerValidation(argc, argv);
  int tcc = inf.readInt(1, 1000, "t");
  inf.readEoln();

  int s = 0;
  for (int tc = 1; tc <= tcc; tc++) {
    setTestCase(tc);
    int n = inf.readInt(0, 200'000, "n");
    s += n;
    inf.readSpace();
    inf.readInt(1, n, "k");
    inf.readEoln();
    inf.readInts(n, 0, 1'000'000'000, "a");
    inf.readEoln();
  }
  ensuref(s <= 200'000,
          "Sum of n over all testcase must be less or equal to 200000");
  inf.readEof();
}
