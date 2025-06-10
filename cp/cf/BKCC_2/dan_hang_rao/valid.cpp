#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
  registerValidation(argc, argv);

  int testCaseCount = inf.readInt(1, 1000, "t");
  inf.readEoln();
  int sn = 0;
  for (int testCase = 1; testCase <= testCaseCount; testCase++) {
    setTestCase(testCase);
    int n = inf.readInt(1, 2 * 100'000, "n");
    sn += n;
    inf.readSpace();
    inf.readInt(1, 1'000'000'000, "r");
    inf.readSpace();
    inf.readInt(1, 1'000'000'000, "c");

    inf.readEoln();
    inf.readInts(n, 1, 1'000'000'000, "h");
    inf.readEoln();
    inf.readInts(n, 1, 1'000'000'000, "w");
    inf.readEoln();
  }
  ensure(sn <= 200'000);
  inf.readEof();
}
