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

  int s = 0, sq = 0;
  for (int tc = 1; tc <= tcc; tc++) {
    set<pair<int, int>> st;
    setTestCase(tc);
    int n = inf.readInt(1, 500'000, "n");
    inf.readSpace();
    int m = inf.readInt(0, min(n * n, 500'000), "m");
    s += n;
    inf.readEoln();
    for (int i = 0; i < m; i++) {
      int x = inf.readInt(1, n, "x");
      inf.readSpace();
      int y = inf.readInt(1, n, "y");
      inf.readEoln();
      ensuref(st.find({x, y}) == st.end(), "x, y must be unique");
      st.insert({x, y});
    }

    int q = inf.readInt(1, 500'000, "q");
    sq += q;
    inf.readEoln();

    for (int i = 0; i < q; i++) {
      int k = inf.readInt(1, n, "k");
      inf.readSpace();
      inf.readInt(1, n - k + 1, "u");
      inf.readSpace();
      inf.readInt(1, n - k + 1, "v");
      inf.readEoln();
    }
  }
  ensuref(s <= 500'000 && sq <= 500'000,
          "Sum of n and q over all testcase must be less or equal to 500000");
  inf.readEof();
}
