#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int t = inf.readInt(1, 200000, "t");
    inf.readEoln();
    long long sumN = 0, sumQ = 0;
    for (int tc = 1; tc <= t; tc++) {
        setTestCase(tc);
        int n = inf.readInt(1, 200000, "n");
        inf.readSpace();
        int q = inf.readInt(1, 200000, "q");
        inf.readEoln();
        sumN += n; sumQ += q;
        ensuref(sumN <= 200000, "sum of n over test cases exceeds 200000");
        ensuref(sumQ <= 200000, "sum of q over test cases exceeds 200000");
        for (int i = 1; i <= q; i++) {
            int type = inf.readInt(1, 2, format("type[%d]", i));
            inf.readSpace();
            inf.readInt(1, 1000000000, format("a[%d]", i));
            if (type == 1) {
                inf.readSpace();
                inf.readInt(1, 1000000000, format("b[%d]", i));
            }
            inf.readEoln();
        }
    }
    inf.readEof();
    return 0;
}
