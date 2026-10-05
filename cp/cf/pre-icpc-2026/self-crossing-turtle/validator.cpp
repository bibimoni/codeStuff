#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int t = inf.readInt(1, 10000, "t");
    inf.readEoln();
    int totalN = 0;
    for (int tc = 0; tc < t; ++tc) {
        setTestCase(tc + 1);
        int n = inf.readInt(1, 200000, "n");
        inf.readEoln();
        totalN += n;
        ensuref(totalN <= 200000, "sum of n must not exceed 200000");
        for (int i = 0; i < n; ++i) {
            inf.readLong(1, 1000000000LL, format("d[%d]", i + 1).c_str());
            if (i + 1 == n) inf.readEoln();
            else inf.readSpace();
        }
    }
    inf.readEof();
}
