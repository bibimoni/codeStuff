#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
  registerValidation(argc, argv);

  int testCaseCount = inf.readInt(1, 10000, "t");
  inf.readEoln();

  for (int testCase = 1; testCase <= testCaseCount; testCase++) {
    setTestCase(testCase);
    int n = inf.readInt(2, 2 * 100000, "n");
    inf.readEoln();
    inf.readInts(n, 1, 1000000000, "a");
    inf.readEoln();
  }

  inf.readEof();
}
