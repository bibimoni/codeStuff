#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int t = inf.readInt(1, 300000, "t");
    inf.readEoln();
    long long sumN = 0, sumQ = 0;
    for (int tc = 1; tc <= t; tc++) {
        setTestCase(tc);
        int n = inf.readInt(2, 300000, "n");
        inf.readSpace();
        int q = inf.readInt(1, 300000, "q");
        inf.readEoln();
        sumN += n; sumQ += q;
        ensuref(sumN <= 300000, "sum of n over test cases exceeds 300000");
        ensuref(sumQ <= 300000, "sum of q over test cases exceeds 300000");
        for (int i = 1; i <= n; i++) {
            inf.readLong(-1000000000LL, 1000000000LL, format("a[%d]", i));
            if (i < n) inf.readSpace(); else inf.readEoln();
        }
        for (int i = 1; i <= n; i++) {
            inf.readLong(-1000000000LL, 1000000000LL, format("b[%d]", i));
            if (i < n) inf.readSpace(); else inf.readEoln();
        }
        for (int e = 1; e <= q; e++) {
            int tp = inf.readInt(1, 3, format("event %d type", e));
            inf.readSpace();
            if (tp == 1) {
                int s = inf.readInt(1, n + 1, format("event %d s", e));
                inf.readSpace();
                int tt = inf.readInt(1, n + 1, format("event %d t", e));
                inf.readEoln();
                ensuref(s < tt, "event %d: s = %d must be < t = %d", e, s, tt);
            } else {
                inf.readInt(1, n, format("event %d x", e));
                inf.readSpace();
                inf.readLong(-1000000000LL, 1000000000LL, format("event %d w", e));
                inf.readEoln();
            }
        }
    }
    inf.readEof();
    return 0;
}
