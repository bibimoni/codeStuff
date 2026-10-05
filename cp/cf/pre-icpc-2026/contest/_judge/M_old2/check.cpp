#include "testlib.h"

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    int pos = 0;
    while (!ans.seekEof()) {
        long long expected = ans.readLong();
        if (ouf.seekEof())
            quitf(_wa, "output ended before token %d", pos + 1);
        long long found = ouf.readLong();
        if (found != expected)
            quitf(_wa, "token %d differs: expected %lld, found %lld", pos + 1, expected, found);
        ++pos;
    }
    if (!ouf.seekEof())
        quitf(_wa, "extra output after %d tokens", pos);
    quitf(_ok, "%d integer tokens", pos);
}
