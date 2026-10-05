#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int t = inf.readInt(1, 200000, "t");
    inf.readEoln();
    long long sumN = 0;
    for (int tc = 1; tc <= t; tc++) {
        setTestCase(tc);
        int n = inf.readInt(1, 200000, "n");
        inf.readSpace();
        int k = inf.readInt(1, n, "k");
        inf.readEoln();
        sumN += n;
        ensuref(sumN <= 200000, "sum of n over test cases exceeds 200000");
        for (int i = 1; i <= n; i++) {
            inf.readInt(1, 1000000000, format("a[%d]", i));
            if (i < n) inf.readSpace(); else inf.readEoln();
        }
    }
    inf.readEof();
    return 0;
}
