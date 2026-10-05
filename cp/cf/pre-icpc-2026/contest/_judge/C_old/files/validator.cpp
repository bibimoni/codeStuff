#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int T = inf.readInt(1, 100, "T");
    inf.readEoln();

    for (int tc = 1; tc <= T; ++tc) {
        setTestCase(tc);

        inf.readLong(
            1LL,
            1'000'000'000'000'000'000LL,
            "N"
        );
        inf.readEoln();
    }

    inf.readEof();
}