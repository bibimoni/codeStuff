#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
  registerValidation(argc, argv);

  int testCaseCount = inf.readInt(1, 1000, "t");
  inf.readEoln();

  for (int testCase = 1; testCase <= testCaseCount; testCase++) {
    setTestCase(testCase);
    int n = inf.readInt(1, 100, "n");
    inf.readSpace();
    int m = inf.readInt(1, n, "m");
    inf.readSpace();
    int t = inf.readInt(1, n, "t");
    inf.readEoln();
    auto a = inf.readInts(m, 1, n, "a");
    inf.readEoln();
    auto b = inf.readInts(t, 1, n, "b");
    inf.readEoln();

    set<int> st(a.begin(), a.end());
    set<int> st1(b.begin(), b.end());
    ensure(st.size() == m && st1.size() == t);
  }
  inf.readEof();
}
