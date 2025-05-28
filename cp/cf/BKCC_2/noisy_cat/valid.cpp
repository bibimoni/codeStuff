#include "testlib.h"
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
  registerValidation(argc, argv);

  int testCaseCount = inf.readInt(1, 1000, "t");
  inf.readEoln();
  int sn = 0, sm = 0;
  for (int testCase = 1; testCase <= testCaseCount; testCase++) {
    setTestCase(testCase);
    int n = inf.readInt(1, 200'000, "n");
    inf.readSpace();
    int m = inf.readInt(1, 200'000, "m");
    inf.readSpace();
    int k = inf.readInt(1, min(m, n), "k");
    ensure(k % 2 == 1);
    inf.readEoln();
    for (int i = 0; i < n; i++) {
      inf.readInts(m, 0, 1'000'000'000, "aij");
      inf.readEoln();
    }
    // inf.readEoln();

    sn += n;
    sm += m;
  }
  ensure(sn * sm <= 200'000);
  inf.readEof();
}
