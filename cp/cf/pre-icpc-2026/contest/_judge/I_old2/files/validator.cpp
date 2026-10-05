#include "testlib.h"
#include <set>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int t = inf.readInt(1, 200000, "t");
    inf.readEoln();
    long long sumNM = 0;
    for (int tc = 1; tc <= t; tc++) {
        setTestCase(tc);
        int n = inf.readInt(1, 200000, "n");
        inf.readSpace();
        int m = inf.readInt(1, 200000, "m");
        inf.readEoln();
        long long nm = 1LL * n * m;
        ensuref(nm <= 200000, "n*m exceeds 200000");
        sumNM += nm;
        ensuref(sumNM <= 200000, "sum of n*m over test cases exceeds 200000");
        vector<vector<int>> g(n, vector<int>(m));
        int pipes = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                g[i][j] = inf.readInt(0, 15, format("g[%d][%d]", i + 1, j + 1));
                ensuref(__builtin_popcount(g[i][j]) != 1,
                        "g[%d][%d] = %d has exactly one opening", i + 1, j + 1, g[i][j]);
                if (g[i][j]) pipes++;
                if (j + 1 < m) inf.readSpace(); else inf.readEoln();
            }
        int q = inf.readInt(0, pipes, "q");
        inf.readEoln();
        set<pair<int,int>> seen;
        for (int i = 1; i <= q; i++) {
            int r = inf.readInt(1, n, format("r[%d]", i));
            inf.readSpace();
            int c = inf.readInt(1, m, format("c[%d]", i));
            inf.readEoln();
            ensuref(g[r - 1][c - 1] != 0, "impact %d hits empty tile (%d,%d)", i, r, c);
            ensuref(seen.insert({r, c}).second, "tile (%d,%d) is hit twice", r, c);
        }
    }
    inf.readEof();
    return 0;
}
