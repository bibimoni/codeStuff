#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int t = inf.readInt(1, 100000, "t");
    inf.readEoln();
    long long sumN = 0;
    for (int tc = 1; tc <= t; tc++) {
        setTestCase(tc);
        int n = inf.readInt(1, 100000, "n");
        inf.readEoln();
        sumN += n;
        ensuref(sumN <= 100000, "sum of n over test cases exceeds 100000");
        for (int i = 1; i <= n; i++) {
            inf.readLong(-1000000000LL, 1000000000LL, format("a[%d]", i));
            if (i < n) inf.readSpace(); else inf.readEoln();
        }
    }
    inf.readEof();
    return 0;
}
