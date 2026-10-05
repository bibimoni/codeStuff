#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int t = inf.readInt(1, 300, "t");
    inf.readEoln();
    int sumN = 0;
    for (int tc = 1; tc <= t; ++tc) {
        setTestCase(tc);
        int n = inf.readInt(1, 300, "n");
        inf.readSpace();
        inf.readInt(0, n * (n - 1) / 2, "m");
        inf.readSpace();
        inf.readLong(1LL, 1000000000000000000LL, "k");
        inf.readEoln();
        sumN += n;
        ensuref(sumN <= 300, "sum of n must not exceed 300");
    }
    inf.readEof();
}
