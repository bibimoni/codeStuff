#include "testlib.h"
using namespace std;

// Exact match of the int64 answer sequence (ncmp-style, explicit extra-token rejection).
int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    int n = 0;
    while (!ans.seekEof()) {
        n++;
        long long j = ans.readLong();
        long long p = ouf.readLong();
        if (j != p)
            quitf(_wa, "%d%s answer differs - expected: '%lld', found: '%lld'",
                  n, englishEnding(n).c_str(), j, p);
    }
    if (!ouf.seekEof())
        quitf(_wa, "participant output contains extra tokens");
    quitf(_ok, "%d answer(s)", n);
}
