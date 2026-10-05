#include "testlib.h"

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    int T = inf.readInt();

    for (int tc = 1; tc <= T; ++tc) {
        setTestCase(tc);
        inf.readLong();
    }

    quitf(_ok, "Interaction accepted");
}