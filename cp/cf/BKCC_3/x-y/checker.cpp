#include "testlib.h"
#include <bits/stdc++.h>
const double EPS = 1E-6;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
int main(int argc, char *argv[]) {
#define int int64_t
  setName("Check the answer for the x-y problem");
  registerTestlibCmd(argc, argv);
  int tt = inf.readInt(1, 10000, "tc"); // n0 testcases
  for (int tc = 1; tc <= tt; tc++) {
    setTestCase(tc);
    int a = inf.readInt();

    int x = ouf.readInt(1, 1'000'000'000, "x");
    ouf.readSpace();
    int y = ouf.readInt(1, 1'000'000'000, "y");
    ouf.readEoln();
    int xa = ans.readInt(1, 1'000'000'000, "xa");
    ans.readSpace();
    int ya = ans.readInt(1, 1'000'000'000, "ya");
    ans.readEoln();

    const int S = sqrt(x + x * y + a);
    if (S * S != x + x * y + a) {
      quitf(_wa, "Wrong answer: %lld, %lld", x, y);
    }
  }
  quitf(_ok, "%lld testcaes", tt);
}
