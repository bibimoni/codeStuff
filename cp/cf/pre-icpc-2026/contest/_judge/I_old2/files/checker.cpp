#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    long long i = 0;
    while (!ans.seekEof() && !ouf.seekEof()) {
        i++;
        long long expected = ans.readLong();
        long long got = ouf.readLong();
        if (expected != got)
            quitf(_wa, "answer %lld differs: expected %lld, found %lld", i, expected, got);
    }
    if (!ans.seekEof()) quitf(_wa, "too few answers: expected more than %lld", i);
    if (!ouf.seekEof()) quitf(_wa, "too many answers: expected exactly %lld", i);
    quitf(_ok, "%lld answers, all correct", i);
}
