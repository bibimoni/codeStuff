#include "testlib.h"
using namespace std;
int main(int argc, char** argv) {
    registerValidation(argc, argv);
    int t = inf.readInt(1, 100, "t"); inf.readEoln();
    long long total = 0;
    for (int tc = 1; tc <= t; tc++) {
        setTestCase(tc);
        int m = inf.readInt(1, 100, "m"); inf.readEoln();
        for (int i = 1; i <= m; i++) {
            string s = inf.readLine();
            ensuref(s.size() >= 1 && s.size() <= 20000, "line %d: bad length %d", i, (int)s.size());
            ensuref(s.front() != ' ' && s.back() != ' ', "line %d: leading/trailing space", i);
            for (char c : s) ensuref(c == ' ' || (c >= 'a' && c <= 'z'), "line %d: bad char %d", i, (int)c);
            total += s.size();
        }
    }
    ensuref(total <= 2000000, "total length %lld exceeds 1000000", total);
    inf.readEof();
    return 0;
}
