#include "testlib.h"

#include <string>

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    int tc = 0;
    while (!ans.seekEof()) {
        setTestCase(++tc);
        std::string expected = ans.readWord();
        std::string found = ouf.readWord();
        for (char& c : expected) c = tolower(c);
        for (char& c : found) c = tolower(c);
        if (expected != found) {
            quitf(_wa, "expected %s, found %s", expected.c_str(), found.c_str());
        }
    }
    ouf.seekEof();
    quitf(_ok, "all answers match");
}
