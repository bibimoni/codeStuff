#include "testlib.h"

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    long long cnt = 0;
    while (!ans.seekEof() && !ouf.seekEof()) {
        cnt++;
        long long jury = ans.readLong();
        long long part = ouf.readLong();
        if (jury != part)
            quitf(_wa, "answer #%lld differs: expected %lld, found %lld", cnt, jury, part);
    }
    if (!ans.seekEof())
        quitf(_wa, "participant ended early: jury still has answers (after #%lld)", cnt);
    if (!ouf.seekEof())
        quitf(_wa, "participant produced extra output (after #%lld answers)", cnt);
    quitf(_ok, "%lld answers", cnt);
}
