#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
  registerValidation(argc, argv);

  int testCaseCount = inf.readInt(1, 10'000, "t");
  inf.readEoln();
  int sum_n = 0, sum_m = 0;
  for (int testCase = 1; testCase <= testCaseCount; testCase++) {
    setTestCase(testCase);
    
    int n = inf.readInt(2, 1'000, "n");
    inf.readSpace();
    
    int m = inf.readInt(2, 1'000, "m");
    inf.readSpace();
    
    int k = inf.readInt(1, min(n, m) / 2, "k");
    inf.readEoln();
    sum_n += n, sum_m += m;

    for (int i = 0; i < n; i++) {
      inf.readInts(m, 0, int(1e9), "ai");
      inf.readEoln();
    }
    // inf.readSpace();
  }
  ensure(sum_n <= 1'000);
  ensure(sum_m <= 1'000);
  inf.readEof();
}