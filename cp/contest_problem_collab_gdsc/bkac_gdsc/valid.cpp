#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
  registerValidation(argc, argv);

  int testCaseCount = inf.readInt(1, 100, "t");
  inf.readEoln();
  for (int testCase = 1; testCase <= testCaseCount; testCase++) {
    setTestCase(testCase);
    
    int n = inf.readInt(4, 100, "n");
    inf.readEoln();
    
    inf.readToken("[A-Z]{1,100}", "s");
    inf.readEoln();
    // inf.readSpace();
  }
  inf.readEof();
}