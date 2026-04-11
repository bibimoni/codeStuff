#include "testlib.h"

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
using namespace std;

int main(int argc, char *argv[]) {
  registerValidation(argc, argv);
  int tcc = inf.readInt(1, 10000, "t");
  inf.readEoln();
  for (int tc = 1; tc <= tcc; tc++) {
    setTestCase(tc);
    inf.readInt(1, 1'000'000'000, "a");
    inf.readEoln();
  }
  inf.readEof();
}
