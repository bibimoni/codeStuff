#include "testlib.h"
#include <string>

using namespace std;

const long long MIN_A = -1e9;
const long long MAX_A = 1e9;

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  int T = opt<int>("t");
  string type = opt<string>("type");
  printf("%d\n", T);
  for (int i = 0; i < T; ++i) {
    long long A = rnd.next(MIN_A, MAX_A);
    if (type == "random") {
      A = rnd.next(MIN_A, MAX_A);
    } else if (type == "small") {
      A = rnd.next(-100LL, 100LL);
    } else if (type == "max_pos") {
      A = rnd.wnext(MIN_A, MAX_A, 5);
      if (A < MAX_A - 10000) {
        A = rnd.next(MAX_A - 10000LL, MAX_A);
      }
    } else if (type == "max_neg") {
      A = rnd.wnext(MIN_A, MAX_A, -5);
      if (A > MIN_A + 10000) {
        A = rnd.next(MIN_A, MIN_A + 10000LL);
      }
    }
    printf("%lld\n", A);
  }

  return 0;
}
